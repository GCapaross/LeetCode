// Brute forcing would be removing each pair individually and then trying out with it and seeing which has more
// Thats an easy approach, I want another one

// There's also a sliding window approach
// We can use two pointers to maintain a window of nums without any conflicting pairs inside
// For each conflicting pair removed, we slide through the array counting valid subarrays efficiently
// We track the last occurrence of each element to quickly adjust the window boundaries when conflicts arise
// This reduces the complexity compared to brute force and handles large inputs effectively

// The problem with this approach (brute force) is the time limit exceeded -> corrected now with sliding window but still time limit exceeded
// class Solution {
// public:
//     long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
//         long long maxCount = 0;

//         for (int removeIdx = 0; removeIdx < (int)conflictingPairs.size(); ++removeIdx) {
//             vector<vector<int>> g(n + 1);
//             for (int i = 0; i < (int)conflictingPairs.size(); ++i) {
//                 if (i != removeIdx) {
//                     int a = conflictingPairs[i][0], b = conflictingPairs[i][1];
//                     g[a].push_back(b);
//                     g[b].push_back(a);
//                 }
//             }

//             vector<int> lastSeen(n + 1, -1);
//             int left = 0;
//             long long count = 0;

//             for (int right = 0; right < n; ++right) {
//                 int num = right + 1;

//                 int newLeft = left;
//                 for (int conflictWith : g[num]) {
//                     if (lastSeen[conflictWith] >= left) {
//                         newLeft = max(newLeft, lastSeen[conflictWith] + 1);
//                     }
//                 }
//                 left = newLeft;

//                 lastSeen[num] = right;
//                 count += (right - left + 1);
//             }

//             maxCount = max(maxCount, count);
//         }

//         return maxCount;
//     }
// };

// This solution isnt working in all cases
// So I made this adjustment
// 1. Among all conflicting pairs, find those with the minimum (a + b) sum.
// 2. Among those, pick the one with the smallest abs(a - b) distance.
// 3. Remove that pair.
// 4. Count all valid subarrays that do not contain both elements of any remaining pair.

// It also didn't work this solution because [[9,8],[5,9]]
// We should remove 9,8 and not 5,9
// And it makes sense
// Building heurisitcs doesnt guarantee that it will always work, Ill look up on them later on

// class Solution {
// public:
//     long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
//         // We need to count in conflicting pairs the integer that appears more often
//         // Basically a common conflicting pair
//         // Make hash map to count appearances
//         // Or a list where the index corresponds to the number and the value in that index corresponds to the number of occurrences
//         // There's no equal conflicting pairs
//         // Intuitively I think we can takeout any conflicting pair, of the highest appeared number

//         vector<int> appearances(n + 1, 0); // to safely index from 1 to n

//         // n < 10000
//         for (int i = 0; i < conflictingPairs.size(); i++) {
//             for (int num : conflictingPairs[i]) {
//                 appearances[num] += 1;
//                 // this will create a list for example [0, 1, 0, 0, 2] -> meaning 1 has 1 appearance and 4 has 2 appearances
//             }
//         }

//         // Now we get the index with the highest value, meaning number with more occurrences
//         int first_highest = 0;
//         int max_val = 0;
//         for (int j = 1; j <= n; j++) {
//             if (appearances[j] > max_val) {
//                 max_val = appearances[j];
//                 first_highest = j;
//                 // j representes the index of the array which represents the real number
//                 // We also need to take out the second highest????
//                 // From the example if this was true we wouldve taken out [2,5] but taking out [1,2] or [3,5] would be the same
//                 // So probably it has to be the highest with the smallest
//             }
//         }

//         // Get the index with the smallest non-zero appearance
//         int second_smallest = 0;
//         int min_val = INT_MAX;
//         for (int j = 1; j <= n; j++) {
//             if (appearances[j] > 0 && appearances[j] < min_val) {
//                 min_val = appearances[j];
//                 second_smallest = j;
//             }
//         }

//         // We need to now get the pair
//         // From here we just need to make all combinations from 1 -> n
//         // And take out those that have the two numbers

//         // Remove the pair that has both highest and smallest (if any)
//         int removeIndex = -1;
//         for (int i = 0; i < conflictingPairs.size(); i++) {
//             int a = conflictingPairs[i][0], b = conflictingPairs[i][1];
//             if ((a == first_highest && b == second_smallest) || (a == second_smallest && b == first_highest)) {
//                 removeIndex = i;
//                 break;
//             }
//         }

//         // if no such pair, just remove the first one
//         // actually now that I think about it, maybe we should remove the pair whose sum is the smallest
//         // for example [[10,5],[3,8]]
//         // we should remove [3,8] because being smaller numbers they will show up more often
//         // if this doesnt work ill make the difference between the highest and smallest value between them both

//         // remove the pair that invalidates the most subarrays
//         long long maxInvalid = -1;
//         removeIndex = 0;
//         for (int i = 0; i < conflictingPairs.size(); i++) {
//             int a = conflictingPairs[i][0], b = conflictingPairs[i][1];
//             int left = min(a, b);
//             int right = max(a, b);
//             long long invalid = (long long)left * (n - right + 1); // subarrays containing both a and b
//             if (invalid > maxInvalid) {
//                 maxInvalid = invalid;
//                 removeIndex = i;
//             }
//         }

//         vector<vector<int>> remainingPairs;
//         for (int i = 0; i < conflictingPairs.size(); i++) {
//             if (i != removeIndex) {
//                 remainingPairs.push_back(conflictingPairs[i]);
//             }
//         }

//         long long count = 0;
//         for (int start = 0; start < n; start++) {
//             unordered_set<int> seen;
//             for (int end = start; end < n; end++) {
//                 seen.insert(end + 1); // nums = [1, 2, ..., n]
//                 bool conflict = false;
//                 for (auto& pair : remainingPairs) {
//                     if (seen.count(pair[0]) && seen.count(pair[1])) {
//                         conflict = true;
//                         break;
//                     }
//                 }
//                 if (!conflict) {
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };


// We have an array: [1, 2, 3, 4, 5]
// We want to count ALL possible subarrays (contiguous subsequences)

// What's a subarray? Examples:
// [1] - starts at position 1, ends at position 1
// [1,2] - starts at position 1, ends at position 2  
// [2,3,4] - starts at position 2, ends at position 4
// [3,4,5] - starts at position 3, ends at position 5

// The POSITIONS are just the indices: 1, 2, 3, 4, 5

// The variable 'r' means "right endpoint" - we're looking at all subarrays that END at position r.

// EXAMPLE: When r = 3, we're counting subarrays that end at position 3:
// - [1,2,3] (starts at 1, ends at 3)
// - [2,3] (starts at 2, ends at 3)  
// - [3] (starts at 3, ends at 3)
// That's 3 subarrays ending at position 3.

// CONFLICTING PAIRS:
// If we have conflictingPairs = [[1,4]], it means we CAN'T have both number 1 and number 4 in the same subarray.

// So these subarrays are INVALID:
// - [1,2,3,4] (contains both 1 and 4)
// - [1,3,4] (contains both 1 and 4)  
// - [1,4] (contains both 1 and 4)

// These are VALID:
// - [1,2,3] (has 1 but not 4)
// - [2,3,4] (has 4 but not 1)
// - [4,5] (has 4 but not 1)
// */

class Solution {
public:
    long long maxSubarrays(int n, std::vector<std::vector<int>>& conflictingPairs) {
        // STEP 1: When do conflicts "kick in"?
        // A conflict [1,4] only matters when we reach position 4 or beyond
        // So we group conflicts by their RIGHT side (the bigger number)
        
        std::vector<std::vector<int>> right(n + 1);
        for (const auto& pair : conflictingPairs) {
            int smaller = std::min(pair[0], pair[1]);
            int bigger = std::max(pair[0], pair[1]);
            right[bigger].push_back(smaller);
        }
        
        // For [1,4]: right[4] = [1]
        // This means: "when we reach position 4, we activate the rule: can't include 1"
        
        long long total_subarrays = 0;
        
        // Keep track of which positions we CAN'T start from
        // left[0] = the highest position we can't start from
        // left[1] = the second highest position we can't start from  
        std::vector<long long> left = {0, 0};
        
        // Track how much benefit we get from removing each restriction
        std::vector<long long> bonus(n + 1, 0);
        
        // STEP 2: Go through each ending position
        for (int r = 1; r <= n; ++r) {
            
            // STEP 2a: Activate any new conflicts
            for (int forbidden_start : right[r]) {
                // This conflict says: subarrays ending at r (or later) 
                // cannot start at position forbidden_start (or earlier)
                
                // Update our "can't start from" list
                if (forbidden_start > left[0]) {
                    left[1] = left[0];
                    left[0] = forbidden_start;
                } else if (forbidden_start > left[1]) {
                    left[1] = forbidden_start;
                }
            }
            
            // STEP 2b: Count valid subarrays ending at position r
            // We can start from position (left[0] + 1) up to position r
            long long valid_endings_at_r = r - left[0];
            total_subarrays += valid_endings_at_r;
            
            // STEP 2c: Calculate bonus if we remove the most restrictive rule
            if (left[0] > 0) {
                // If we remove the most restrictive rule (left[0]), 
                // then we can start from position (left[1] + 1) instead
                // This gives us (left[0] - left[1]) extra starting positions
                bonus[left[0]] += left[0] - left[1];
            }
        }
        
        // STEP 3: Find the maximum bonus
        long long max_bonus = 0;
        for (long long b : bonus) {
            max_bonus = std::max(max_bonus, b);
        }
        
        return total_subarrays + max_bonus;
    }
};
