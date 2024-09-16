class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int na = a.size(), nb = b.size();
        vector<vector<long long>> dp(na + 1, vector<long long>(nb + 1, INT_MIN));
        for (int j = 0; j <= nb; j++) {
            dp[na][j] = 0;
        }
        for (int i = na - 1; i >= 0; i--) {
            for (int j = nb - 1; j >= 0; j--) {
                long long ntaken = dp[i][j + 1];
                long long taken = static_cast<long long>(a[i]) * b[j] + dp[i + 1][j + 1];
                dp[i][j] = max(ntaken, taken);
            }
        }

        return dp[0][0];
    }
};
