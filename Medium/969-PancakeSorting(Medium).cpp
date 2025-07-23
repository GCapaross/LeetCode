class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        // From the examples
        // Input: arr = [3,2,4,1]
        // Output: [4,2,4,3]
        // Explanation: 
        // We perform 4 pancake flips, with k values 4, 2, 4, and 3.
        // Starting state: arr = [3, 2, 4, 1]
        // After 1st flip (k = 4): arr = [1, 4, 2, 3]
        // After 2nd flip (k = 2): arr = [4, 1, 2, 3]
        // After 3rd flip (k = 4): arr = [3, 2, 1, 4]
        // After 4th flip (k = 3): arr = [1, 2, 3, 4], which is sorted.

        // It looks like k is determined by the distance between the first number of the array and the smallest number
        // But if I have [1,3,2] this isn't true and for this example I'd have [2, 3, 2] which gives -> [3,1,2] -> [2,1,3] -> [1,2,3]
        // Does the minimum length for k array correspond to arr.length()?
        // I have 10 * arr.length as an extension to non optimality
        // What if we don't have repeated numbers

        // [1,3,2,4] -> 2314 -> 3214 -> 1234 --> 323
        // We do it reversly
        // We try to get the last element to the last spot
        // It says all integers are unique so we don't have to worry

        // We get the highest number unordered to the first position, and then we put it to last position
        // And then we start subtracting from size - 1 and we find the corresponding number and distance to first position and distance to last position

        int size = arr.size();  
        vector<int> arr_k;

        while (size > 1) {
            int maxIndex = 0;
            for (int i = 0; i < size; ++i) {
                if (arr[i] == size) {
                    maxIndex = i;
                    break;
                }
            }

            // We need to update the array with the changes made
            if (maxIndex != size - 1) {
                if (maxIndex != 0) {
                    reverse(arr.begin(), arr.begin() + maxIndex + 1);
                    arr_k.push_back(maxIndex + 1);
                }

                reverse(arr.begin(), arr.begin() + size);
                arr_k.push_back(size);
            }

            size -= 1;
        }

        return arr_k;
    }
};
