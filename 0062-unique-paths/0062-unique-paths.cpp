class Solution {
public:
    int helper(vector<vector<int>>& dp, int& m, int& n, int i, int j) {
        if(i >= m or j >= n) {
            return 0;
        } else if(i == m - 1 and j == n - 1) {
            return 1;
        } else if(dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = helper(dp, m, n, i + 1, j) + helper(dp, m, n, i, j + 1);
    }
    int uniquePaths(int m, int n) {
        int ans = 0;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(dp, m, n, 0, 0);
    }
};