class Solution {
public:
    int helper(int i, int j, int k, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp) {
        if(i < 0 or j < 0) {
            return -1e7;
        }
        if(i == 0 and j == 0) {
            return coins[0][0] < 0 and k > 0 ? 0 : coins[0][0];
        }
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        int up = coins[i][j] < 0 and k > 0 ? max(coins[i][j] + helper(i - 1, j, k, coins, dp), helper(i - 1, j, k - 1, coins, dp)) : coins[i][j] + helper(i - 1, j, k, coins, dp);
        int left = coins[i][j] < 0 and k > 0 ? max(coins[i][j] + helper(i, j - 1, k, coins, dp), helper(i, j - 1, k - 1, coins, dp)) : coins[i][j] + helper(i, j - 1, k, coins, dp);
        return dp[i][j][k] = max(up, left);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (3, INT_MIN)));
        dp[0][0][0]=coins[0][0];
        if (coins[0][0]<0) {
            dp[0][0][1]=0; 
            dp[0][0][2]=0;
        } else {
            dp[0][0][1]=dp[0][0][2]=coins[0][0];
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < 3; k++) {
                    if (i==0 && j==0) continue;
                    if(i > 0) {
                        int up = coins[i][j] < 0 and k > 0 ? max(coins[i][j] + dp[i - 1][j][k], dp[i - 1][j][k - 1]) : coins[i][j] + dp[i - 1][j][k];
                        dp[i][j][k] = max(dp[i][j][k], up);
                    }
                    if(j > 0) {
                        int left = coins[i][j] < 0 and k > 0 ? max(coins[i][j] + dp[i][j - 1][k], dp[i][j - 1][k - 1]) : coins[i][j] + dp[i][j - 1][k];
                        dp[i][j][k] = max(dp[i][j][k], left);
                    }
                }
            }
        }
        return max(dp[m - 1][n - 1][0], max(dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]));
    }
};