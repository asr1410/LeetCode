class Solution {
public:
    long long distributeCandies(int n, int limit) {
        const int k = 3;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= k; i++) {
            vector<long long> prefix(n + 2, 0);
            for (int j = 0; j <= n; j++) {
                prefix[j + 1] = prefix[j] + dp[i - 1][j];
            }

            for (int j = 0; j <= n; j++) {
                int l = max(0, j - limit);
                int r = j;
                dp[i][j] = prefix[r + 1] - prefix[l];
            }
        }

        return dp[k][n];
    }
};
