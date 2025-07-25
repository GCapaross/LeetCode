#include<numeric>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        // Order first?
        // Or I do two cases, if theres negative numbers we just remove them
        // If the array is only constituted of negative numbers, we choose the smaller one
        set<int> to_sum;
        int lowest_number = -99999999999;

        for (auto num : nums) {
            if (num >= 0) {
                to_sum.insert(num);
            }
            else {
                if (num >= lowest_number) {
                    lowest_number = num;
                }
            }
        }
        if (to_sum.size() == 0) {
            to_sum.insert(lowest_number);
        }

        int sum = 0;
        int size = to_sum.size();
        sum = accumulate(to_sum.begin(), to_sum.end(), 0);
        return sum;
    }
};
