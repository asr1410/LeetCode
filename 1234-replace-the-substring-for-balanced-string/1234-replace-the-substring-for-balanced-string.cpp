class Solution {
public:
    int balancedString(string s) {
        int qc = 0, wc = 0, ec = 0, rc = 0, n = s.size(), ans = n;
        
        // Count occurrences of each character
        for(int i = 0; i < n; i++) {
            qc += s[i] == 'Q';
            wc += s[i] == 'W';
            ec += s[i] == 'E';
            rc += s[i] == 'R';
        }
        
        // Calculate the required counts to balance the string
        qc -= n / 4;
        wc -= n / 4;
        ec -= n / 4;
        rc -= n / 4;
        
        // If the string is already balanced, return 0
        if (qc == 0 && wc == 0 && ec == 0 && rc == 0) {
            return 0;
        }
        
        int qt = 0, wt = 0, et = 0, rt = 0;
        
        // Sliding window approach to find the minimum length balanced substring
        for(int l = 0, r = 0; r < n; r++) {
            qt += s[r] == 'Q';
            wt += s[r] == 'W';
            et += s[r] == 'E';
            rt += s[r] == 'R';
            
            // Adjust the left pointer of the window if the window becomes valid
            while(qc <= qt and wc <= wt and ec <= et and rc <= rt) {
                ans = min(ans, r - l + 1);
                qt -= s[l] == 'Q';
                wt -= s[l] == 'W';
                et -= s[l] == 'E';
                rt -= s[l] == 'R';
                l++;
            }
        }
        
        // Return the minimum length found
        return ans;
    }
};
