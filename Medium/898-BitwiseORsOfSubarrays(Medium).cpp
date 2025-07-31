// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& arr) {
//         set<int> unique_values;
//         int n = arr.size();


//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 int sum = 0;
//                 for (int k = i; k <= j; k++) {
//                     sum = sum | arr[k];
//                 }
//                 unique_values.insert(sum);
//             }
//         }
//         return unique_values.size();
//     }
// };

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;       
        unordered_set<int> cur;      
        unordered_set<int> next;    

        for (int num : arr) {
            next.clear();
            next.insert(num);
            for (int val : cur) {
                next.insert(val | num);
            }
            cur = next;
            res.insert(cur.begin(), cur.end());
        }
        return res.size();
    }
};
