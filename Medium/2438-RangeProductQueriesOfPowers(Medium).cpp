class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // Powers will correspond to the numbers of 1's in n -> bitwise
        // n = 14 = 2 + 4 + 8 -> 1110 -> 1000 + 0100 + 0010
        const int MOD = 1'000'000'007;
        vector<int> powers;
        int bit = 1;
        int temp = n;
        while (temp > 0) {
            if (temp & 1) powers.push_back(bit);
            bit <<= 1;
            temp >>= 1;
        }
        vector<int> result;
        for (auto& q : queries) {
            long long product = 1;
            for (int i = q[0]; i <= q[1]; i++) {
                product = (product * powers[i]) % MOD;
            }
            result.push_back((int)product);
        }
        return result;
    }
};
