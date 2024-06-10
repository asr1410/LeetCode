class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        for(int i = s.size() - 1; i >= 0; i--) {
            if(ans.size()) {
                ans += ' ';
            }
            while(i >= 0 and s[i] == ' ') {
                i--;
            }
            string temp = "";
            while(i >= 0 and s[i] != ' ') {
                temp += s[i];
                i--;
            }
            reverse(temp.begin(), temp.end());
            ans += temp;
        }
        while(ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};