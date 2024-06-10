class Solution {
public:
    bool ispall(string& s, int l, int r) {
        while(l < r) {
            if(s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";
        int anslen = 0;
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                if(ispall(s, i, j)) {
                    if(anslen < j - i + 1) {
                        anslen = j - i + 1;
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
        
    }
};