class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf = 0, i = 0, n = s.length();
        vector<int> count(26);
        for (int j = 0; j < n; ++j) {
            maxf = max(maxf, ++count[s[j] - 'A']);
            if(j - i + 1 > maxf + k) {
                --count[s[i++] - 'A'];
            }
        }
        return n - i;
    }
};