class Solution {
public:
    bool helper(int i, int j, int health, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || health < 1) {
            return false;
        }
        if (i == 0 && j == 0) {
            return (grid[i][j] == 1 && health >= 2) || (grid[i][j] == 0 && health >= 1);
        }
        if (dp[i][j] >= health) {
            return false;
        }
        dp[i][j] = health;
        health -= grid[i][j];
        return  helper(i - 1, j, health, grid, dp) || helper(i, j - 1, health, grid, dp) || helper(i + 1, j, health, grid, dp) || helper(i, j + 1, health, grid, dp);
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return helper(m - 1, n - 1, health, grid, dp);
    }
};
