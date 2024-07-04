class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), maxf = 0, ans = 0;
        vector<int> map(26);
        for(int l = 0, r = 0; r < n; r++) {
            maxf = max(maxf, ++map[s[r] - 'A']);
            if(r - l + 1 - maxf > k) {
                map[s[l] - 'A']--;
                l++;
            }
            if(r - l + 1 - maxf <= k) {
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};