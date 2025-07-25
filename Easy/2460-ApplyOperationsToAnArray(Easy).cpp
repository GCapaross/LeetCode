class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // We need to be careful with out of bounds access
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] != 0 && nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0; // The counting method that I had previously done wouldn't work because:
                // Although we were adding the zeros, when traversing the list again, we weren't removing the merged numbers
                // So if we had [1,1,0,2]
                // Then we would have [2,1,0,2] -> and it would add 1 to the new vector and it shouldn't
                // But now it is corrected
            }
        }

        vector<int> result;
        // We're going to add onto a new vector the numbers after altered
        for (int num : nums) {
            if (num != 0) result.push_back(num);
        }

        while (result.size() < n) {
            result.push_back(0);
        }

        return result;
    }
};
