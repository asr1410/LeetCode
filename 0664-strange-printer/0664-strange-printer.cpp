class Solution {
public:
    int n;
    int dp[101][101];
    int helper(int i, int j, const string& s) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MAX;
        if (s[i] == s[j]) {
            ans = helper(i, j - 1, s);
        } else {
            for (int k = i; k < j; ++k) {
                if (s[k] == s[j]) {
                    ans = min(ans, helper(i, k, s) + helper(k + 1, j - 1, s));
                }
            }
            ans = min(ans, helper(i, j - 1, s) + 1);
        }

        return dp[i][j] = ans;
    }

    int strangePrinter(string s) {
        s.erase(unique(s.begin(), s.end()), s.end());
        memset(dp, -1, sizeof(dp));
        n = s.size();
        return helper(0, n - 1, s);
    }
};
