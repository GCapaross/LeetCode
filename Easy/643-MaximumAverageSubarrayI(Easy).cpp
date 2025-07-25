class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int windowSum = 0;

        if (k == 1) {
            return static_cast<double>(*max_element(nums.begin(), nums.end()));
        }

        for (int i = 0; i < k; ++i) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;
        for (int i = k; i < nums.size(); ++i) {
            windowSum += nums[i] - nums[i - k]; // To sum the next number and subtract the previous one
            maxSum = max(maxSum, windowSum); // Then we check which sum is higher
            // Since we only want the average, we don't need to care about finding out which of the numbers we need
            // And I was overcomplicating that aspect
            // As well as firstly I thought that the average would be done
            // Being the numerator the k numbers and the denominator the remaining ones
            // Which would lead to a lot of problems specially with negative numbers
            // Example -5 / -5 = +1
        }

        return static_cast<double>(maxSum) / k;
    }
};
