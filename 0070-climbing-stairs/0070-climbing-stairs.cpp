class Solution {
public:
    int helper(int n, vector<int>& dp) {
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 1, dp[1] = 2;
        return helper(n - 1, dp);
    }
};
