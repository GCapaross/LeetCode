class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max_diff = -1;
        // Nums aren't negative so we don't have to worry
        for (int i = 0; i < nums.size() - 1; i++) {
            // This would be if the different would be absolute, but they only want nums[i] and nums[j] , no need to be followed
            // if (abs(nums[i] - nums[i+1]) > max_diff) {
            //     max_diff = abs(nums[i] - nums[i+1]);
            // }
            for (int j = i + 1; j < nums.size(); j++) {
                // It's obligatory that (nums[j] > nums[i])
                if (((nums[j] - nums[i]) > max_diff) && (nums[j] - nums[i]) != 0) {
                    max_diff = (nums[j] - nums[i]);
                }
            }
        }
        return max_diff;
    }
};
