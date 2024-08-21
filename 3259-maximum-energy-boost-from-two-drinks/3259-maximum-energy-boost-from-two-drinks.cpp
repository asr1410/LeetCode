class Solution {
public:
    long long helper(int i, int n, vector<int>& a, vector<int>& b, int c, vector<vector<long long>>& dp) {
        if(i >= n) {
            return 0;
        }
        if(c == -1) {
            long long ana = a[i] + helper(i + 1, n, a, b, 0, dp);
            long long bnb = b[i] + helper(i + 1, n, a, b, 1, dp);
            long long anb = a[i] + helper(i + 2, n, a, b, 1, dp);
            long long bna = b[i] + helper(i + 2, n, a, b, 0, dp);
            return max(ana, max(bnb, max(anb, bna)));
        }
        if(dp[i][c] != -1) {
            return dp[i][c];
        }
        if(c == 0) {
            long long ana = a[i] + helper(i + 1, n, a, b, 0, dp);
            long long anb = a[i] + helper(i + 2, n, a, b, 1, dp);
            return dp[i][c] = max(ana, anb);
        }
        long long bnb = b[i] + helper(i + 1, n, a, b, 1, dp);
        long long bna = b[i] + helper(i + 2, n, a, b, 0, dp);
        return dp[i][c] = max(bnb, bna);
    }
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<vector<long long>> dp(n, vector<long long> (2, -1));
        return helper(0, n, a, b, -1, dp);
    }
};