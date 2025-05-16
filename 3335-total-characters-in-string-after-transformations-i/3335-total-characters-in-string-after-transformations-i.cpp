class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[100001][27];
    int helper(char c, int t) {
        int diff = 'z' - c;
        if(diff >= t) {
            return 1;
        }
        if(dp[t][c - 'a'] != -1) {
            return dp[t][c - 'a'];
        }
        long long ans = 0;
        ans += helper('a', t - diff - 1);
        ans %= mod;
        ans += helper('b', t - diff - 1);
        ans %= mod;
        return dp[t][c - 'a'] = ans;
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