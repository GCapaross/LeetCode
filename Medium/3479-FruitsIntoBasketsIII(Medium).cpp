
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int rem = 0;
        int n = baskets.size();

        for (auto& fruit : fruits) {
            int var = 1;

            for (int i = 0; i < n; i++) {
                if (fruit <= baskets[i]) {
                    baskets[i] = 0;
                    var = 0;
                    break;
                }
            }

            rem += var;
        }

        return rem;
    }
};




// class SegmentTree {
// private:
//     vector<int> tree;
//     int size;

//     void build(int node, int l, int r, const vector<int>& data) {
//         if (l == r) {
//             tree[node] = data[l];
//         } else {
//             int mid = (l + r) / 2;
//             build(2 * node, l, mid, data);
//             build(2 * node + 1, mid + 1, r, data);
//             tree[node] = min(tree[2 * node], tree[2 * node + 1]);
//         }
//     }

//     void update(int node, int l, int r, int idx, int val) {
//         if (l == r) {
//             tree[node] = val;
//         } else {
//             int mid = (l + r) / 2;
//             if (idx <= mid)
//                 update(2 * node, l, mid, idx, val);
//             else
//                 update(2 * node + 1, mid + 1, r, idx, val);
//             tree[node] = min(tree[2 * node], tree[2 * node + 1]);
//         }
//     }

//     int query(int node, int l, int r, int ql, int qr) {
//         if (qr < l || r < ql)
//             return INT_MAX;
//         if (ql <= l && r <= qr)
//             return tree[node];
//         int mid = (l + r) / 2;
//         return min(query(2 * node, l, mid, ql, qr),
//                    query(2 * node + 1, mid + 1, r, ql, qr));
//     }

// public:
//     SegmentTree(const vector<int>& data) {
//         size = data.size();
//         tree.resize(4 * size);
//         build(1, 0, size - 1, data);
//     }

//     int queryMin(int l, int r) {
//         return query(1, 0, size - 1, l, r);
//     }

//     void markUsed(int idx) {
//         update(1, 0, size - 1, idx, INT_MAX);
//     }
// };


// class Solution {
// public:
//     int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
//         int n = baskets.size();
//         vector<pair<int, int>> sortedBaskets;
//         for (int i = 0; i < n; ++i) {
//             sortedBaskets.emplace_back(baskets[i], i); 
//         }
//         sort(sortedBaskets.begin(), sortedBaskets.end());

//         vector<int> originalIndices(n);
//         for (int i = 0; i < n; ++i) {
//             originalIndices[i] = sortedBaskets[i].second;
//         }

//         SegmentTree st(originalIndices);
//         int unplaced = 0;

//         for (int fruit : fruits) {
//             int left = 0, right = n - 1, pos = n;
//             while (left <= right) {
//                 int mid = (left + right) / 2;
//                 if (sortedBaskets[mid].first >= fruit) {
//                     pos = mid;
//                     right = mid - 1;
//                 } else {
//                     left = mid + 1;
//                 }
//             }

//             if (pos == n) {
//                 unplaced++; 
//                 continue;
//             }

//             int idx = st.queryMin(pos, n - 1);
//             if (idx == INT_MAX) {
//                 unplaced++;
//             } else {
//                 for (int i = pos; i < n; ++i) {
//                     if (sortedBaskets[i].second == idx) {
//                         st.markUsed(i);
//                         break;
//                     }
//                 }
//             }
//         }

//         return unplaced;
//     }
// };
