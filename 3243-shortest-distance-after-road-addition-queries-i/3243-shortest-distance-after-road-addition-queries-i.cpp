class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> roads(n);
        vector<int> dp(n), res;
        iota(begin(dp), end(dp), 0);
        for (const auto &q : queries) {
            roads[q[1]].push_back(q[0]);
            for (int i = q[1]; i < n; ++i) {
                dp[i] = min(dp[i], dp[i - 1] + 1);
                for (int l : roads[i])
                    dp[i] = min(dp[i], dp[l] + 1);
            }
            res.push_back(dp[n - 1]);
        }
        return res;
    }
};
