class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0, mx = 0;
        for(auto &c:s) {
            if(c == '(') {
                mx++;
                mn++;
            } else if(c == ')') {
                mx--;
                mn--;
            } else {
                mx++;
                mn--;
            }
            if(mx < 0) {
                return false;
            }
            if(mn < 0) {
                mn = 0;
            }
        }
        return mn == 0;
    }
};