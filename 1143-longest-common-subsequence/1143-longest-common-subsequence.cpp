class Solution {
public:
    int helper(int n, int m, string& s, string& t, vector<vector<int>>& dp) {
        if(n < 0 or m < 0) {
            return 0;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        if(s[n] == t[m]) {
            return dp[n][m] = 1 + helper(n - 1, m - 1, s, t, dp);
        }
        return dp[n][m] = max(helper(n - 1, m, s, t, dp), helper(n, m - 1, s, t, dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(n - 1, m - 1, text1, text2, dp);
    }
};