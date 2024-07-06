class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0;
        for(char c = 'A'; c <= 'Z'; c++) {
            for(int l = 0, r = 0, count = 0; r < n; r++) {
                count += s[r] != c;
                while(count > k) {
                    count -= s[l] != c;
                    l++;
                }
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};