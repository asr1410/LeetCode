class Solution {
public:
    int helper(int n, vector<int>& dp) {
        if(dp[n] != -1) {
            return dp[n];
        }
        int otaken = helper(n - 1, dp);
        int ttaken = n >= 2 ? helper(n - 2, dp) : 0;
        return dp[n] = otaken + ttaken;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            int otaken = dp[i - 1];
            int ttaken = i >= 2 ? dp[i - 2]: 0;
            dp[i] = otaken + ttaken;
        }
        return dp[n];
    }
};