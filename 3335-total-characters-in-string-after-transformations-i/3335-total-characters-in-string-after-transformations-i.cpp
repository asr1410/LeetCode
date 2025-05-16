class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[100001][27];
    int helper(char c, int t) {
        int diff = 'z' - c;
        int idx = c - 'a';
        if(diff >= t) {
            return 1;
        }
        if(dp[t][idx] != -1) {
            return dp[t][idx];
        }
        return dp[t][idx] = (helper('a', t - diff - 1) + helper('b', t - diff - 1)) % mod;
    }
    int lengthAfterTransformations(string s, int t) {
        long long ans = 0;
        memset(dp, -1, sizeof(dp));
        for(const char c : s) {
            ans += helper(c, t);
            ans %= mod;
        }
        return ans;
    }
};