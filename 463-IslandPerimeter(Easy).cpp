int dirs[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    int borders = 0;
                    for (int k=0; k<4; ++k) {
                        int x = i + dirs[k][0];
                        int y = j + dirs[k][1];

                        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                            if (grid[x][y] == 0) borders++;
                        } else borders++;
                    }

                    ans += borders;
                }
            }
        }
        return ans;
    }
};
