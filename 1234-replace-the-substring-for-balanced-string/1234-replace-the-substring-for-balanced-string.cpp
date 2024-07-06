class Solution {
public:
    int balancedString(string s) {
        int qc = 0, wc = 0, ec = 0, rc = 0, n = s.size(), ans = n;
        for(char c : s) {
            qc += c == 'Q';
            wc += c == 'W';
            ec += c == 'E';
            rc += c == 'R';
        }
        qc -= n / 4;
        wc -= n / 4;
        ec -= n / 4;
        rc -= n / 4;
        if (qc == 0 && wc == 0 && ec == 0 && rc == 0) return 0;
        int qt = 0, wt = 0, et = 0, rt = 0;
        for(int l = 0, r = 0; r < n; r++) {
            qt += s[r] == 'Q';
            wt += s[r] == 'W';
            et += s[r] == 'E';
            rt += s[r] == 'R';
            while (l <= r && qt >= qc && wt >= wc && et >= ec && rt >= rc) {
                ans = min(ans, r - l + 1);
                qt -= s[l] == 'Q';
                wt -= s[l] == 'W';
                et -= s[l] == 'E';
                rt -= s[l] == 'R';
                l++;
            }
        }
        return ans;
    }
};