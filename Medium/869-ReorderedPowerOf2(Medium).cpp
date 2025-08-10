class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end()); // sort digits of n

        // Check all powers of 2 up to 1 billion (since n <= 10^9 in the problem)
        for (int i = 0; i < 31; i++) {
            int power = 1 << i;
            string p = to_string(power);
            sort(p.begin(), p.end()); // sort digits of power of 2
            if (s == p) return true;   // same digit frequency
        }
        return false;
    }
};
