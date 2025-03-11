class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0}; 
        int r = 0, l = 0, n = s.size(), ans = 0;

        while (r < n) {
            while (r < n && !(count[0] && count[1] && count[2])) {
                count[0] += s[r] == 'a';
                count[1] += s[r] == 'b';
                count[2] += s[r] == 'c';
                r++;
            }
            if (!(count[0] && count[1] && count[2])) break;
            int remaining = n - r + 1;
            while (count[0] && count[1] && count[2]) {
                ans += remaining;
                count[0] -= s[l] == 'a';
                count[1] -= s[l] == 'b';
                count[2] -= s[l] == 'c';
                l++;
            }
        }
        return ans;
    }
};
