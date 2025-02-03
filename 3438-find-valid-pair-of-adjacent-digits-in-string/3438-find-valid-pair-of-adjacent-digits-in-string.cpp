class Solution {
public:
    string findValidPair(string s) {
        int n = s.size();
        int cnt[10] = {0};
        for(const char& c : s)
            cnt[c - '0']++;
        for(int i = 1; i < n; i++) {
            int curr = s[i] - '0';
            int prev = s[i - 1] - '0';
            if(curr != prev and cnt[prev] == prev and cnt[curr] == curr) {
                return to_string(prev) + to_string(curr);
            }
        }
        return "";
    }
};