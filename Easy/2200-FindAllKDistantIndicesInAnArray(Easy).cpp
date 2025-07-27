#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> positions;
        vector<int> output;

        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (nums[i] == key) {
                positions.push_back(i);
            }
        }

        for (int j = 0; j < size; j++) {
            for (int p : positions) {
                if (abs(j - p) <= k) {
                    output.push_back(j);
                    break;  
                }
            }
        }

        return output;
    }
};
