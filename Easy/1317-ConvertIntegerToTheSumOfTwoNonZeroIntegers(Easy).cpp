class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        
        vector<int> arr;

        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (!hasZero(a) && !hasZero(b)) {
                arr.push_back(a);
                arr.push_back(b);
                return (arr);
            }
        }
        return arr;
    }

    bool hasZero(int k) {
        string num = to_string(k);
        return (num.find("0") != string::npos);
    }


};
