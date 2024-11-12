class Solution {
public:
    const int mod = 1e9  + 7;
    
    int helper(char c, int t, vector<vector<int>>& dp) {
        if(c + t - 'a' < 26) {
            return 1;
        }
        if(dp[c - 'a'][t] != -1) {
            return dp[c - 'a'][t];
        }
        long long ans = 0;
        ans += helper('a', t - ('z' - c + 1), dp);
        ans %= mod;
        ans += helper('b', t - ('z' - c + 1), dp);
        ans %= mod;
        return dp[c - 'a'][t] = ans;
    }
    
    int lengthAfterTransformations(string s, int t) {
        long long ans = 0;
        vector<vector<int>> dp(26, vector<int> (t + 1, -1));
        for(char c : s) {
            ans += helper(c, t, dp);
            ans %= mod;
        }
        return ans;
    }
};