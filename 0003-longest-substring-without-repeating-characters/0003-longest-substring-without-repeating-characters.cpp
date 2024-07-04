class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256, -1);
        int ans = 0, n = s.size();
        for(int i = -1, j = 0; j < n; j++) {
            if(map[s[j]] > i) {
                i = map[s[j]];
            }
            map[s[j]] = j;
            ans = max(ans, j - i);
        }
        return ans;
    }
};