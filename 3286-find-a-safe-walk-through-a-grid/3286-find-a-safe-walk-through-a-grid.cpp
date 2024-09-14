class Solution {
public:
    bool helper(int i, int j, int m, int n, int health, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i < 0 or j < 0 or i == m or j == n or health < 1 or grid[i][j] == -1) {
            return false;
        }
        if(i == m - 1 and j == n - 1) {
            return (grid[i][j] == 1 and health >= 2) or (grid[i][j] == 0 and health >= 1);
        }
        if(dp[i][j] >= health) {
            return false;
        }
        dp[i][j] = health;
        int val = grid[i][j];
        health -= val;
        grid[i][j] = -1;
        int top = helper(i - 1, j, m, n, health, grid, dp);
        int left = helper(i, j - 1, m, n, health, grid, dp);
        int right = helper(i, j + 1, m, n, health, grid, dp);
        int down = helper(i + 1, j, m, n, health, grid, dp);
        health += val;
        grid[i][j] = val;
        return top or left or right or down;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), 0));
        return helper(0, 0, grid.size(), grid[0].size(), health, grid, dp);
    }
};