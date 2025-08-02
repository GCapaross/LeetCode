class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        // We put both arrays in a dictionary where the keys correspond to the numbers and the values to the number of ocorrunces
        // If any value is odd then we return -1
        // which also account for it being 1, meaning existing only in one array

        unordered_map<int, int> count;
        map<int, int> count1, count2;
        // two different dictionaries for each different array -> 1 and 2
        // for us to compare after
        int n = basket1.size();
        int globalMin = INT_MAX;

        for (int i = 0; i < n; ++i) {
            count[basket1[i]]++;
            count1[basket1[i]]++;
            globalMin = min(globalMin, basket1[i]);

            count[basket2[i]]++;
            count2[basket2[i]]++;
            globalMin = min(globalMin, basket2[i]);
        }


        // if its odd the number return -1
        for (auto& [fruit, freq] : count) {
            if (freq % 2 != 0)
                return -1;
        }

        // we rearrange the values of the keys for them to become the same values corresponding to the same keys

        vector<int> extra1, extra2;


        // a good way to compare would be through the values
        // higher or smaller
        for (auto& [fruit, _] : count) {
            int c1 = count1[fruit];
            int c2 = count2[fruit];
            int diff = abs(c1 - c2) / 2;

            if (c1 > c2) {
                for (int i = 0; i < diff; ++i)
                    extra1.push_back(fruit);
            } else if (c2 > c1) {
                for (int i = 0; i < diff; ++i)
                    extra2.push_back(fruit);
            }
        }

        // now we sort both to match cheapest 
        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend()); // reverse sort to match min from one side to max from other

        long long totalCost = 0;
        int swaps = extra1.size();

        for (int i = 0; i < swaps; ++i) {
            int a = extra1[i];
            int b = extra2[i];
            // Cost is either direct swap min(a,b) or two-step via global minimum
            totalCost += min({a, b, 2 * globalMin});
        }

        return totalCost;
    }
};
