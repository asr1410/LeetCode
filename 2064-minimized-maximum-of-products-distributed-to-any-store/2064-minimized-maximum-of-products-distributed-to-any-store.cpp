class Solution {
public:
    bool check(int m, vector<int>& q, int n) {
        int count = 0;
        for(int t : q) {
            count += (t + m - 1) / m;
        }
        return count <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = 1e8;
        int ans = 0;
        while(l <= r) {
            int m = (l + r) / 2;
            if(check(m, quantities, n)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
