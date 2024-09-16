class Solution {
public:
    long long helper(int i, int j, int na, int nb, vector<int>& a, vector<int>& b, vector<vector<long long>>& dp) {
        if (i == na) {
            return 0;
        }
        if (j == nb) {
            return -1e9;
        }
        if(dp[j][i] != -1) {
            return dp[j][i];
        }
        long long ntaken = helper(i, j + 1, na, nb, a, b, dp);
        long long taken = static_cast<long long>(a[i]) * b[j] + helper(i + 1, j + 1, na, nb, a, b, dp);
        return dp[j][i] = max(ntaken, taken);
    }

    long long maxScore(vector<int>& a, vector<int>& b) {
        int na = a.size(), nb = b.size();
        vector<vector<long long>> dp(nb, vector<long long> (na, -1));
        return helper(0, 0, na, nb, a, b, dp);
    }
};
