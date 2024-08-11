class Solution {
public:
    int helper(vector<vector<int>>& dp, int i, int j) {
        if(i < 0 or j < 0) {
            return 0;
        } else if(i == 0 and j == 0) {
            return 1;
        } else if(dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = helper(dp, i, j - 1) + helper(dp, i - 1, j);
    }
    int uniquePaths(int m, int n) {
        int ans = 0;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(dp, m - 1, n - 1);
    }
};