class Solution {
public:
    int maxScore(string s) {
        int oc = 0, zc = 0;
        for(char c : s) {
            oc += c == '1';
        }
        int ans = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            zc += s[i] == '0';
            oc -= s[i] == '1';
            ans = max(ans, zc + oc);
        }
        return ans;
    }
};