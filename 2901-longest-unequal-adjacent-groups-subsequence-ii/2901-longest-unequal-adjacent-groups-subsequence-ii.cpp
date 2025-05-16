class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> choice;

    bool check(string& c, string& p) {
        int cnt = 0;
        for (int i = 0; i < c.size(); i++) {
            cnt += c[i] != p[i];
        }
        return cnt == 1;
    }

    int helper(int c, int p, vector<string>& words, vector<int>& groups) {
        if (c == words.size()) return 0;

        if (dp[c][p + 1] != -1) return dp[c][p + 1];

        int take = 0, notTake = 0;
        if (p == -1 || (groups[c] != groups[p] && words[c].size() == words[p].size() && check(words[c], words[p]))) {
            take = 1 + helper(c + 1, c, words, groups);
        }
        notTake = helper(c + 1, p, words, groups);
        return dp[c][p + 1] = max(take, notTake);
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        dp.assign(n, vector<int>(n + 1, -1));

        int cnt = helper(0, -1, words, groups);
        vector<string> result;
        int i = 0, prev = -1;

        while (cnt > 0 and i < n) {
            while (i < n and dp[i][prev + 1] == cnt) {
                i++;
            }
            result.push_back(words[i - 1]);
            prev = i - 1;
            cnt--;
        }

        return result;
    }
};
