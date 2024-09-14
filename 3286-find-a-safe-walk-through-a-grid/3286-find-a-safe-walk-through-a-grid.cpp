class Solution {
public:
    bool helper(int i, int j, int health, const vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || j < 0 || i >= m || j >= n || health <= 0) {
            return false;
        }
        if (i == 0 && j == 0) {
            return (grid[i][j] == 1 && health >= 2) || (grid[i][j] == 0 && health >= 1);
        }
        if (dp[i][j] >= health) {
            return false;
        }
        dp[i][j] = health;

        int val = grid[i][j];
        health -= val;

        bool up = helper(i - 1, j, health, grid, dp);
        bool left = helper(i, j - 1, health, grid, dp);
        bool down = helper(i + 1, j, health, grid, dp);
        bool right = helper(i, j + 1, health, grid, dp);

        return up || left || down || right;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, health, grid, dp);
    }
};
