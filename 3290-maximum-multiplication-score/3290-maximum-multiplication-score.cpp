class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<long long> dp(4, LLONG_MIN);
        for (int i = 0; i < n; ++i) {
            for (int j = 3; j >= 0; --j) {
                if (j == 0 || dp[j-1] != LLONG_MIN) {
                    dp[j] = max(dp[j], (j > 0 ? dp[j-1] : 0) + (long long)a[j] * b[i]);
                }
            }
        }
        
        return dp[3];
    }
};