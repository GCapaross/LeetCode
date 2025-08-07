// Brute force wouldn't work here
// The less the kids overlap, the better
// Thinking about a greedy search where each kid picks rooms with the most fruits
// But skip rooms already visited by others
// Another idea: DFS for each kid, mark visited rooms, all paths end at (n-1, n-1)
// Then pick the best paths for each kid and subtract overlaps
// Put those results together and pick the max

// Here: Greedy beam search per kid
// Handle conflicts by making sure only one kid gets fruits from a room
// Use top-K pruning to keep things efficient
// Then fix double counting in the end

// Dynamic programming approach

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        
        // Child 1 moves diagonally from (0,0) to (n-1,n-1) always
        int child1_fruits = 0;
        for (int i = 0; i < n; i++) {
            child1_fruits += fruits[i][i];
        }
        
        // Child 2 starts at top-right corner, moves down with options
        int child2_fruits = maxFruitsChild2(fruits, n);
        
        // Child 3 starts at bottom-left corner, moves right with options
        int child3_fruits = maxFruitsChild3(fruits, n);
        
        return child1_fruits + child2_fruits + child3_fruits;
    }
    
private:
    int maxFruitsChild2(vector<vector<int>>& fruits, int n) {
        // DP for kid starting at (0, n-1)
        // dp[i][j] = max fruits collected reaching (i, j)
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][n-1] = fruits[0][n-1];
        
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == -1) continue;
                
                // Moves: down-left, down, down-right
                vector<int> nextCols = {j-1, j, j+1};
                
                for (int nextJ : nextCols) {
                    if (nextJ >= 0 && nextJ < n) {
                        // Skip main diagonal except final cell, to avoid overlap with kid1
                        if (i+1 == nextJ && i+1 != n-1) continue;
                        
                        int newFruits = dp[i][j];
                        if (i+1 != nextJ || i+1 == n-1) { // Collect fruits except main diagonal except at end
                            newFruits += fruits[i+1][nextJ];
                        }
                        
                        dp[i+1][nextJ] = max(dp[i+1][nextJ], newFruits);
                    }
                }
            }
        }
        
        // Subtract destination cell fruits already counted by child1
        return dp[n-1][n-1] - fruits[n-1][n-1];
    }
    
    int maxFruitsChild3(vector<vector<int>>& fruits, int n) {
        // DP for kid starting at (n-1, 0)
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[n-1][0] = fruits[n-1][0];
        
        for (int j = 0; j < n-1; j++) {
            for (int i = 0; i < n; i++) {
                if (dp[i][j] == -1) continue;
                
                // Moves: up-right, right, down-right
                vector<int> nextRows = {i-1, i, i+1};
                
                for (int nextI : nextRows) {
                    if (nextI >= 0 && nextI < n) {
                        // Skip main diagonal except final cell to avoid overlap with kid1
                        if (nextI == j+1 && j+1 != n-1) continue;
                        
                        int newFruits = dp[i][j];
                        if (nextI != j+1 || j+1 == n-1) { // Collect fruits except main diagonal except at end
                            newFruits += fruits[nextI][j+1];
                        }
                        
                        dp[nextI][j+1] = max(dp[nextI][j+1], newFruits);
                    }
                }
            }
        }
        
        // Subtract destination cell fruits already counted by child1
        return dp[n-1][n-1] - fruits[n-1][n-1];
    }
};
