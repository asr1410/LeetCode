class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        for(int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for(int j = 0; j < n; j++) {
                if(i == 0 and j == 0) {
                    temp[j] = 1;
                } else {
                    if(i > 0)   temp[j] += dp[j];
                    if(j > 0)   temp[j] += temp[j - 1];
                }
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};