#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // So, first Ill travel the array
        // I'll start counting unique numbers until a repetition
        // While saving that sub-array
        // Then I'll keep the biggest subarray and sum the numbers inside of it
        // I could traverse the array several times and add to a map, but I want a more optimal solution
        unordered_set<int> unique_subarray;
        int left = 0, sum = 0, maxSum = 0;
        // [4, 2, 4, 5, 6, 7]  -> Doing the window technique
        //     |          |    -> Im using two markers left and right, and if 
        for (int right = 0; right < nums.size(); ++right) {
            while (unique_subarray.count(nums[right])) {
                unique_subarray.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            unique_subarray.insert(nums[right]);
            sum += nums[right];
            // At first I was making a confusion, because finding the maximum value isn't the longest subarray, so we just need the maximum sum, so we keep saving until a repeated number appearance
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
