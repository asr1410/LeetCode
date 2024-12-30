class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[100001];
    int helper(int zero, int one, int limit) {
        if (limit < 0) {
            return 0;
        }
        if (dp[limit] != -1) {
            return dp[limit];
        }
        return dp[limit] = (1 + helper(zero, one, limit - one) + helper(zero, one, limit - zero)) % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof(dp));
        return (helper(zero, one, high) - helper(zero, one, low - 1) + mod) % mod;
    }
};
