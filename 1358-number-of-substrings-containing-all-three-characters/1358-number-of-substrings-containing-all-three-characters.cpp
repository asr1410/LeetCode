class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(26);
        int i = 0, n = s.size(), ans = 0;
        for (int j = 0; j < n; ++j) {
            count[s[j] - 'a']++;
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                ans += (n - j);
                count[s[i] - 'a']--;
                i++;
            }
        }
        return ans;
    }
};