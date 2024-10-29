class Solution {
public:
    int helper(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (j == n - 1) return 0;
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int f = (i > 0 && j < n - 1 && grid[i][j] < grid[i - 1][j + 1]) ? 1 + helper(i - 1, j + 1, m, n, grid, dp) : 0;
        int s = (j < n - 1 && grid[i][j] < grid[i][j + 1]) ? 1 + helper(i, j + 1, m, n, grid, dp) : 0;
        int t = (i < m - 1 && j < n - 1 && grid[i][j] < grid[i + 1][j + 1]) ? 1 + helper(i + 1, j + 1, m, n, grid, dp) : 0;
        return dp[i][j] = max(f, max(s, t));
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        int maxMoves = 0;
        for (int i = 0; i < m; i++) {
            maxMoves = max(maxMoves, helper(i, 0, m, n, grid, dp));
        }
        return maxMoves;
    }
};
