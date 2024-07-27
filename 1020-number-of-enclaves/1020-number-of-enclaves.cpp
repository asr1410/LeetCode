class Solution {
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int& rows, int& cols, int row, int col) {
        if(row >= 0 and row < rows and col >= 0 and col < cols and vis[row][col] == 0 and grid[row][col] == 1) {
            vis[row][col] = 1;
            dfs(grid, vis, rows, cols, row - 1, col);
            dfs(grid, vis, rows, cols, row, col - 1);
            dfs(grid, vis, rows, cols, row, col + 1);
            dfs(grid, vis, rows, cols, row + 1, col);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int> (cols, 0));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1 and(i == 0 or i == rows - 1 or j == 0 or j == cols - 1)) {
                    dfs(grid, vis, rows, cols, i, j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                 ans += grid[i][j] == 1 and vis[i][j] == 0;
            }
        }
        return ans;
    }
};