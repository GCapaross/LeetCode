class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> last_seen(32, -1); // last seen position of each bit

        for (int i = n - 1; i >= 0; --i) {
            for (int b = 0; b < 32; ++b) {
                if ((nums[i] >> b) & 1) {
                    last_seen[b] = i;
                }
            }

            int max_len = i;
            for (int b = 0; b < 32; ++b) {
                if (last_seen[b] != -1) {
                    max_len = std::max(max_len, last_seen[b]);
                }
            }

            res[i] = max_len - i + 1;
        }

        return res;
    }
};








// This approach works but it's O(n^2) so I could make exceptions from the 3 test cases but I'm gonna try to approach above this one
// O(n*32)

//         vector<int> sizes_subarrays;

//         // It's not a set
//         // It might have repeated numbers
//         // I should first put the numbers in a set or not and findout the max bitwise OR for each array
//         // I can register the last change for the OR

//         int counter = 0;

//         while (counter != nums.size()) {
//             int last_index = counter; // Corresponds to index
//             int currentOR = 0;
//             int last_change = 0;

//             for (int i = counter; i < nums.size(); i++) {
//                 last_change = currentOR;
//                 currentOR = currentOR | nums[i];
//                 if (currentOR != last_change) {
//                     last_index = i;
//                 }
//             }

//             // Fix: if OR never changed  nums[i] = 0, we still need to take size 1
//             sizes_subarrays.push_back(max(1, last_index - counter + 1));
//             counter++;
//         }

//         return sizes_subarrays;
//     }
// };
