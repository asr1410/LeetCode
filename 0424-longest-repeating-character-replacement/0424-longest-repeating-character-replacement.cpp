class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(256);
        int n = s.size(), ans = 0, maxf = 0;
        for(int l = 0, r = 0; r < n; r++) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);
            if(r - l - maxf + 1 <= k) {
                ans = max(ans, r - l + 1);
            } else {
                count[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};