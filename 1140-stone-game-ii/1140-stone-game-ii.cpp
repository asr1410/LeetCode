class Solution {
public:
    int dp[2][101][101], n;
    int helper(int i, int m, int c, vector<int>& p) {
        if(i >= n) {
            return 0;
        }
        if(dp[c][i][m] != -1) {
            return dp[c][i][m];
        }
        int ans = c == 1 ? -1 : INT_MAX, temp = 0, dist = min(2 * m, n - i);
        for(int x = 1; x <= dist; x++) {
            temp += p[i + x - 1];
            if(c == 1) {
                ans = max(ans, temp + helper(i + x, max(m, x), 0, p));
            } else {
                ans = min(ans, helper(i + x, max(x, m), 1, p));
            }
        }
        return dp[c][i][m] = ans;
    }
    int stoneGameII(vector<int>& p) {
        n = p.size();
        memset(dp, -1, sizeof(dp));
        return helper(0, 1, 1, p);
    }
};