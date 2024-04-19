int numIslands(char** grid, int gridSize, int* gridColSize) {
    int output = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                output++;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }
    return output;
}

void dfs(char** grid, int gridSize, int* gridColSize, int row, int col) {
    if (row < 0 || row >= gridSize || col < 0 || col >= gridColSize[row] || grid[row][col] != '1') {
        return;
    }


    grid[row][col] = '0';

    dfs(grid, gridSize, gridColSize, row + 1, col);
    dfs(grid, gridSize, gridColSize, row - 1, col);
    dfs(grid, gridSize, gridColSize, row, col + 1);
    dfs(grid, gridSize, gridColSize, row, col - 1);
}
