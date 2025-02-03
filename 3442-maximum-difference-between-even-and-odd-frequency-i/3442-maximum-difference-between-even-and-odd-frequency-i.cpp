class Solution {
public:
    int maxDifference(string s) {
        int cnt[26] = {0};

        for(const char& c : s) {
            cnt[c - 'a']++;
        }

        int mn = 101, mx = 0;

        for(int i = 0; i < 26; i++) {
            if(cnt[i] > 0) {
                if(cnt[i] & 1) {
                    mx = max(mx, cnt[i]);
                } else {
                    mn = min(mn, cnt[i]);
                }
            }
        }
        return mx - mn;
    }
};