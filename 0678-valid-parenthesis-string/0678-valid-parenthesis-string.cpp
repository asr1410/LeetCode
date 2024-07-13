class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0, mx = 0;
        for(auto &c:s) {
            if(c == '(') {
                mx++;
                mn++;
            }
            if(c == ')') {
                mx--;
                mn = max(mn - 1, 0);
            }
            if(c == '*') {
                mx++;
                mn = max(mn - 1, 0);
            }
            if(mx < 0) {
                return false;
            }
        }
        return mn == 0;
    }
};