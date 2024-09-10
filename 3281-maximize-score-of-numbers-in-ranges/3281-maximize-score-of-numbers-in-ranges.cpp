class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        long long n = start.size();
        long long l = LLONG_MAX, r = LLONG_MIN, ans = 0;

        for (int i = 1; i < n; i++) {
            long long t = start[i] - start[i - 1];
            l = min(l, t);
            r = max(r, t + d);
        }

        while (l <= r) {
            long long gap = (l + r) >> 1;
            bool possible = true;
            long long ls = start[0];

            for (int i = 1; i < n; i++) {
                ls += gap;
                if (ls <= start[i] + d) {
                    ls = max(ls, (long long)start[i]);
                } else {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                ans = gap;
                l = gap + 1;
            } else {
                r = gap - 1;
            }
        }
        return ans;
    }
};
