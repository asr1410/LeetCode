class Solution {
public:
    int helper(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(j == 0) {
            int ans = 0;
            for(int i = 0; i < m; i++) {
                int f = i > 0 and j < n - 1 and grid[i][j] < grid[i - 1][j + 1] ? 1 + helper(i - 1, j + 1, m, n, grid, dp) : 0;
                int s = j < n - 1 and grid[i][j] < grid[i][j + 1] ? 1 + helper(i, j + 1, m, n, grid, dp) : 0;
                int t = i < m - 1 and j < n - 1 and grid[i][j] < grid[i + 1][j + 1] ? 1 + helper(i + 1, j + 1, m, n, grid, dp) : 0;
                ans = max(ans, max(f, max(s, t)));
            }
            return ans;
        }
        int f = i > 0 and j < n - 1 and grid[i][j] < grid[i - 1][j + 1] ? 1 + helper(i - 1, j + 1, m, n, grid, dp) : 0;
        int s = j < n - 1 and grid[i][j] < grid[i][j + 1] ? 1 + helper(i, j + 1, m, n, grid, dp) : 0;
        int t = i < m - 1 and j < n - 1 and grid[i][j] < grid[i + 1][j + 1] ? 1 + helper(i + 1, j + 1, m, n, grid, dp) : 0;
        return dp[i][j] = max(f, max(s, t));
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(0, 0, m, n, grid, dp);
    }
};