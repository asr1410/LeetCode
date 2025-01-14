class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        int k = 2; // Maximum skips allowed

        // Initialize DP table: dp[i][j][k] stores max value collectible at (i, j) with up to k skips.
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1e7)));

        // Base case for the starting point
        for (int skip = 0; skip <= k; ++skip) {
            dp[0][0][skip] = (coins[0][0] < 0 && skip > 0) ? 0 : coins[0][0];
        }

        // Fill DP table
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int skip = 0; skip <= k; ++skip) {
                    if (i == 0 && j == 0) continue; // Skip the starting cell

                    int fromTop = -1e7, fromLeft = -1e7;

                    // Coming from the top
                    if (i > 0) {
                        fromTop = dp[i - 1][j][skip] + coins[i][j];
                        if (coins[i][j] < 0 && skip > 0) {
                            fromTop = max(fromTop, dp[i - 1][j][skip - 1]);
                        }
                    }

                    // Coming from the left
                    if (j > 0) {
                        fromLeft = dp[i][j - 1][skip] + coins[i][j];
                        if (coins[i][j] < 0 && skip > 0) {
                            fromLeft = max(fromLeft, dp[i][j - 1][skip - 1]);
                        }
                    }

                    dp[i][j][skip] = max(fromTop, fromLeft);
                }
            }
        }

        // Return the maximum value at the bottom-right corner with up to 2 skips
        return *max_element(dp[m - 1][n - 1].begin(), dp[m - 1][n - 1].end());
    }
};
