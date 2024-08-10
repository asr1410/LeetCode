class Solution {
public:
    int helper(vector<int>& dp, int n) {
        if(n < 2) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = helper(dp, n - 1) + helper(dp, n - 2);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return helper(dp, n);
    }
};