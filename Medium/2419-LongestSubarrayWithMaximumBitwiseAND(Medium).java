class Solution {
    public int longestSubarray(int[] nums) {
        int maxVal = Integer.MIN_VALUE;
        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
            }
        }
        
        int maxLen = 0, currentLen = 0;
        for (int num : nums) {
            if (num == maxVal) {
                currentLen++;
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                }
            } else {
                currentLen = 0;
            }
        }
        
        return maxLen;
    }
}
