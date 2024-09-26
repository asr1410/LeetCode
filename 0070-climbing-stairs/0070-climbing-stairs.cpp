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
        int p = 1, pp = 0;
        for(int i = 1; i <= n; i++) {
            int otaken = p;
            int ttaken = i >= 2 ? pp: 0;
            pp = p;
            p = otaken + ttaken;
        }
        return p;
    }
};