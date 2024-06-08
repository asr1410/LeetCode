class Solution {
public:
    string clearDigits(string s) {
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                j--;
            } else {
                s[j++] = s[i];
            }
        }
        return s.substr(0, j);
    }
};