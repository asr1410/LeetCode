class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> map(26);
        int i = 0, n = s.size(), ans = 0;
        for (int j = 0; j < n; ++j) {
            map[s[j] - 'a']++;
            while (map[0] && map[1] && map[2]) {
                map[s[i++] - 'a']--;
            }
            ans += i;
        }
        return ans;
    }
};