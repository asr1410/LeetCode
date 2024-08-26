class Solution {
public:
    int dp[20][10001];
    int helper(int i, int diff, vector<int>& rods) {
        if (i < 0) {
            return diff == 0 ? 0 : INT_MIN;
        }
        if (dp[i][diff + 5000] != -1) {
            return dp[i][diff + 5000];
        }
        int ntaken = helper(i - 1, diff, rods);
        int ftaken = rods[i] + helper(i - 1, diff + rods[i], rods);
        int staken = rods[i] + helper(i - 1, diff - rods[i], rods);
        return dp[i][diff + 5000] = max(ntaken, max(ftaken, staken));
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp, -1, sizeof dp);
        int n = rods.size();
        return helper(n - 1, 0, rods) >> 1;
    }
};
