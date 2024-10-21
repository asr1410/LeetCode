class Solution {
public:
    int ans = 0;
    void helper(int n, string& s, unordered_set<string>& uset) {
        if (n == s.size()) {
            ans = max(ans, (int)uset.size());
            return;
        }
        string t;
        for (int i = n; i < s.size(); i++) {
            t += s[i];
            if (uset.insert(t).second) {
                helper(i + 1, s, uset);
                uset.erase(t);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> uset;
        helper(0, s, uset);
        return ans;
    }
};
