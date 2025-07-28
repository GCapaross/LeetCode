class Solution {
public:

    void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& list_of_subsets) {
        list_of_subsets.push_back(current); // Keep all subsets, including empty

        for (int i = index; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            generateSubsets(i + 1, nums, current, list_of_subsets);
            current.pop_back(); // backtrack
        }
    }
    
    int countMaxOrSubsets(vector<int>& nums) {

        // Example [3, 2, 1, 5]
        // 3 -> 0011 2 -> 0010 1 -> 0001 5 -> 0101
        // Max would be 0111
        // Getting the biggest number won't get us the biggest Bitwise OR
        // If we have [8,1] -> 1000 and 0001 the array will be the same -> Output = 1

        // First idea:
        // A Bitwise OR has the following table:
        // 0 | 1 = 1    0 | 0 = 0   1 | 0 = 1   1 | 1 = 1
        // So we need to maximize the number of ones
        // We will traverse and apply OR and all combinations
        // Save to a separate list those who the output will be maximum
        // For exampple, if we get a max number with is a (root of 2 - 1) -> 3, 7, 15
        // We know what the maximum bitwise OR, no zeros to the left and full of ones
        // A very consuming way would be to add all non zero subsets and then check them individually to see if they belong or not
        // This would take a long time, not optimal

        vector<vector<int>> list_of_subsets; // Let's remember, they should be unique, so we can just try adding again that they will keep uniqueness
        vector<int> current;

        generateSubsets(0, nums, current, list_of_subsets);

        // bool isPowerOfTwoMinus1(int a) {
        //     return a > 0 && ((a + 1) & a) == 0;
        // }
        // This won't work because we're not working with sets in the array nums -> meaning it would account for repeated numbers
        // And not unique

        // int max = max_element(nums.begin(), nums.end());

        int output = 0;

        int max_or = 0;
        for (int i = 0; i < nums.size(); i++) {
            max_or = max_or | nums[i];
        }

        for (auto& subset : list_of_subsets) {
            int subset_or = 0;
            for (int i = 0; i < subset.size(); i++) {
                subset_or = subset_or | subset[i];
            }

            if (!subset.empty() && subset_or == max_or) {
                ++output;
            }
        }

        return output;

        // The maximum ammount of subsets is 2^n where n is size of nums
        // int n = nums.size();
        // int num_subsets = 1 << n; // Using shift operation -> shifts 1 n bits to left 1000 <-- 0001 if n = 3

        // if (isPowerOfTwoMinus1(max)) {
        //     // If this is true then the subsets should alll have the bitwise set to this maximum
        //     for (int i = 0; i < num_subsets; i++) {
        //         // Another thing that should be taken into consideration is:
        //         // If we have for example 3 which is the maximum value
        //         // If 3 is in the array all the other members will be able to belong to it
        //     }
        // }

        // Else and as a safe option I can do the bitwise OR between all members, which will give me the biggest number
        // int max = 0;
        // for (int i = 0; i < n; i++) {
        //     max = max | nums[i];
        // }
    }
};
// class Solution {
// public:
//     int max_or = 0;    
//     int count = 0;     

//     void dfs(vector<int>& nums, int index, int current_or) {
//         if (index == nums.size()) {
//             if (current_or == max_or && current_or != 0) {
//                 count++;
//             }
//             return;
//         }

//         dfs(nums, index + 1, current_or | nums[index]);

//         dfs(nums, index + 1, current_or);
//     }

//     int countMaxOrSubsets(vector<int>& nums) {
//         max_or = 0;
//         for (int num : nums) {
//             max_or |= num;
//         }

//         count = 0;
//         dfs(nums, 0, 0);  

//         return count;
//     }
// };
