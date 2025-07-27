class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int hills_valleys = 0;

        // nums[0] will never be counted
        // Same for the last index
        // We want the first non equal index not the following one
        
        int prev = 0;

        for (int i = 1; i < nums.size()-1; i++) {
            if (nums[i] != nums[i+1]) {
                if ((nums[i] > nums[prev] && nums[i] > nums[i+1]) || (nums[i] < nums[prev] && nums[i] < nums[i+1])) {
                    hills_valleys += 1;
                }
                prev = i;
            } 
        }
        return hills_valleys;
    }
};
