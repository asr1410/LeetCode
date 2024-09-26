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
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        return helper(n, dp);
    }
};