class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }

    string longestPalindrome(string s) {
        string ans;
        int anslen = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (isPalindrome(s, i, j) && (j - i + 1) > anslen) {
                    anslen = j - i + 1;
                    ans = s.substr(i, anslen);
                }
            }
        }
        return ans;
    }
};