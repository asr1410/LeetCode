class Solution {
public:
    int minChanges(string s) {
        int ans = 0, zcount = 0, ocount = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                if(ocount % 2 == 1) {
                    ans++;
                    ocount = 0;
                } else {
                    zcount++;
                }
            } else {
                if(zcount % 2 == 1) {
                    ans++;
                    zcount = 0;
                } else {
                    ocount++;
                }
            }
        }
        return ans;
    }
};