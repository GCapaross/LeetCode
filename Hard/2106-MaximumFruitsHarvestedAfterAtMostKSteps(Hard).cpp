class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // First we go the furthest we can left, and the furthest we can right
        // Then we do some sort of merge sort
        // Where we see the max values for each side that I go to
        // For example I can move 8 steps
        // I go 8 to the right and see max value for fruits
        // Then 8 to the left and see max value
        // I see where the biggest values are and go towards them
        // We can also use the position values to subtract to k and using that detect if we can or not reach a certain position

        // Use two arrays: one for positions and one for prefix sums
        vector<int> pos, prefix;
        for (auto& f : fruits) {
            pos.push_back(f[0]);
        }

        int n = fruits.size();
        prefix.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + fruits[i][1];
        }

        int res = 0;

        // Try all positions going left first then right
        for (int x = 0; x <= k; ++x) {
            int left = startPos - x;
            int right = startPos + max(0, k - 2 * x);

            // Binary search for range of reachable positions
            int l = lower_bound(pos.begin(), pos.end(), left) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), right) - pos.begin();

            res = max(res, prefix[r] - prefix[l]);
        }

        // Try all positions going right first then left
        for (int x = 0; x <= k; ++x) {
            int right = startPos + x;
            int left = startPos - max(0, k - 2 * x);

            int l = lower_bound(pos.begin(), pos.end(), left) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), right) - pos.begin();

            res = max(res, prefix[r] - prefix[l]);
        }

        return res;
    }
};
