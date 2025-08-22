class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    minX = min(minX,i);
                    minY = min(minY,j);
                    maxX = max(maxX,i);
                    maxY = max(maxY,j);
                }
            }
        }
        return (maxX-minX+1)*(maxY-minY+1);
    }
};
