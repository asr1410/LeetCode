class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(begin(start), end(start));
        long long n = start.size(), l = 1e9, r = -1e9, ans = 0;
        for(int i = 1; i < n; i++) {
            long long t = start[i] - start[i - 1];
            l = min(l, t);
            r = max(r, t + d);
        }
        while(l <= r) {
            long gap = (l + r) >> 1;
            bool possible = true;
            for(long long i = 1, ls = start[0]; i < n; i++) {
                ls += gap;
                if(ls <= start[i] + d) {
                    ls = max(ls, (long long)start[i]);
                } else {
                    possible = false;
                }
            }
            if(possible) {
                ans = gap;
                l = gap + 1;
            } else {
                r = gap - 1;
            }
        }
        return ans;
    }
};