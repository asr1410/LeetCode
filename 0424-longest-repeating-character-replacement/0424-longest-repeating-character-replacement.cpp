class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, n = s.size();
        for(char c = 'A'; c <= 'Z'; c++) {
            int i = 0, t = k;
            for(int j = 0; j < n; j++) {
                t -= s[j] != c;
                t += t < 0 and s[i++] != c;
            }
            ans = max(ans, n - i);
        }
        return ans;
    }
};