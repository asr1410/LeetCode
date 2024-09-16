class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<long long> dp(4, -1e11);
        for (int bi : b)
            for (int i = 3; i >= 0; --i)
                dp[i] = max(dp[i], (i > 0 ? dp[i - 1] : 0LL) + 1LL * a[i] * bi);
        return dp[3];
    }
};