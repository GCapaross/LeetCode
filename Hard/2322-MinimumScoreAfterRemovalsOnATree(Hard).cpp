// Select one node as initial node and then call dfs in that node
// Iterate and discover all descendents, meaning, node[i] has list_descendents (subtree)
// Iterate through all the pairs and find out the XOR of their sums, with edges to cut
// We'll use Euler Tour to check subtrees
// This will help when removing the 2 edges to determine which nodes are still connected, and from there we can stil calculate the XOR
// We'll brute force the pairs of edges being cut and save the min score, and by applying DFS and then using the timer variable
// We cut down the time for checking descendency


#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // This is a list of adjacents to represent the tree, where tree[i] contains all nodes connected to node i.
    // We'll use this structure to traverse the tree using DFS.
    vector<vector<int>> tree;

    // This array will store the XOR of the entire subtree rooted at each node.
    // For example, if node 2 has children 3 and 4, then subtreeXOR[2] = nums[2] ^ subtreeXOR[3] ^ subtreeXOR[4]
    vector<int> subtreeXOR;

    // These arrays will store the entry and exit times of nodes during DFS.
    // The purpose is to help us later determine ancestor-descendant relationships between nodes in constant time.
    // For example, if in[u] < in[v] && out[u] > out[v], then v is a descendant of u.
    vector<int> in, out;

    // A global timer incremented during DFS to assign entry/exit times to each node. 
    // For the Euler Tour
    int timer = 0;

    // Standard DFS traversal to compute:
    // 1. The XOR value of the entire subtree rooted at each node.
    // 2. The in/out timestamps needed to check ancestry.
    void dfs(int node, int parent, vector<int>& nums) {
        subtreeXOR[node] = nums[node];  // Initialize XOR for the current node using its value.
        in[node] = timer++;             // Record entry time before exploring children.

        for (int child : tree[node]) {
            if (child == parent) continue; // Avoid revisiting the parent node in an undirected graph.

            dfs(child, node, nums);        // Recursively explore the child node.
            subtreeXOR[node] ^= subtreeXOR[child]; // After visiting the child, combine its XOR with the current node.
        }

        out[node] = timer++;  // Record exit time after all children have been processed.
    }

    // Checks whether node `v` is a descendant of node `u` using DFS entry/exit times.
    // If v entered after u and exited before u, it's inside u’s subtree.
    bool isDescendant(int u, int v) {
        return in[v] > in[u] && out[v] < out[u];
    }

    // Main function to find the minimum possible score after removing two edges.
    // Score is defined as the difference between the maximum and minimum XOR of the resulting three components.
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        // Prepare the adjacency list and helper arrays based on the number of nodes.
        tree.resize(n);
        subtreeXOR.resize(n);
        in.resize(n);
        out.resize(n);

        // Build the tree as an undirected graph using the edge list.
        // Each edge connects two nodes, so we add each connection in both directions.
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // Start DFS from node 0 (assumed root), and -1 as the initial parent (none).
        dfs(0, -1, nums);

        // The XOR of the entire tree is stored in the root’s subtree XOR.
        // This represents the total value of all nodes combined.
        int totalXOR = subtreeXOR[0];

        // Initialize result with the maximum possible value to find the minimum later.
        int minScore = INT_MAX;

        // Convert each edge into a directed form where the parent node appears first.
        // We determine this based on in[] timings: the parent will have an earlier entry time than its child.
        // This helps us later treat each edge as separating a clean subtree.
        vector<pair<int, int>> directedEdges;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (in[u] < in[v])
                directedEdges.push_back({u, v}); // u is parent, v is child
            else
                directedEdges.push_back({v, u}); // v is parent, u is child
        }

        // Try all unique pairs of edges (e1, e2). Removing two edges splits the tree into three components.
        // We'll analyze how the subtrees split and compute their XORs accordingly.
        int m = directedEdges.size();
        for (int i = 0; i < m; ++i) {
            auto [a, b] = directedEdges[i]; // First edge: a is parent, b is child (removing edge a->b)
            for (int j = i + 1; j < m; ++j) {
                auto [c, d] = directedEdges[j]; // Second edge: c is parent, d is child (removing edge c->d)

                int x1, x2, x3;

                // There are 3 cases based on the relationship between the two subtrees:
                if (isDescendant(b, d)) {
                    // Case 1: d is inside the subtree rooted at b
                    // In this case, we first cut b->..., and then inside that, we cut d->...
                    // Component 1 = subtree rooted at d
                    // Component 2 = subtree rooted at b but excluding d's subtree
                    // Component 3 = the rest of the tree
                    x1 = subtreeXOR[d];
                    x2 = subtreeXOR[b] ^ subtreeXOR[d];
                    x3 = totalXOR ^ subtreeXOR[b];
                } else if (isDescendant(d, b)) {
                    // Case 2: b is inside the subtree rooted at d
                    // Component 1 = subtree rooted at b
                    // Component 2 = subtree rooted at d but excluding b's subtree
                    // Component 3 = the rest of the tree
                    x1 = subtreeXOR[b];
                    x2 = subtreeXOR[d] ^ subtreeXOR[b];
                    x3 = totalXOR ^ subtreeXOR[d];
                } else {
                    // Case 3: Subtrees rooted at b and d are disjoint
                    // Component 1 = subtree rooted at b
                    // Component 2 = subtree rooted at d
                    // Component 3 = remaining part of the tree
                    x1 = subtreeXOR[b];
                    x2 = subtreeXOR[d];
                    x3 = totalXOR ^ subtreeXOR[b] ^ subtreeXOR[d];
                }

                // Find the max and min among the 3 XORs and compute the score
                int maxVal = max({x1, x2, x3});
                int minVal = min({x1, x2, x3});
                int score = maxVal - minVal;

                // Keep track of the smallest score found so far
                minScore = min(minScore, score);
            }
        }

        // Return the minimum score found across all valid pairs of edge removals
        return minScore;
    }
};
