class Solution {
public:
    int numberOfSubstrings(string s) {
        int ac = 0, bc = 0, cc = 0, ans = 0, n = s.size();
        for(int l = 0, r = 0, count = 0; r < n; r++) {
            ac += s[r] == 'a';
            bc += s[r] == 'b';
            cc += s[r] == 'c';
            while(ac and bc and cc) {
                ans += n - r;
                ac -= s[l] == 'a';
                bc -= s[l] == 'b';
                cc -= s[l] == 'c';
                l++;
            }
        }
        return ans;
    }
};