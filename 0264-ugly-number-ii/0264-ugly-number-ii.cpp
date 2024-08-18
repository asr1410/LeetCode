class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;
        int u1 = 2, u2 = 3, u3 = 5, ui1 = 0, ui2 = 0, ui3 = 0, cu;
        for(int i = 1; i < n; i++) {
            cu = min(u1, min(u2, u3));
            ugly[i] = cu;
            if(cu == u1) {
                ui1++;
                u1 = ugly[ui1] * 2;
            }
            if(cu == u2) {
                ui2++;
                u2 = ugly[ui2] * 3;
            }
            if(cu == u3) {
                ui3++;
                u3 = ugly[ui3] * 5;
            }
        }
        return ugly[n - 1];
    }
};