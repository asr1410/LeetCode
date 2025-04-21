class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long long n = diff.size(), mn = 0, mx = 0;
        for(long long i = 0, prev = 0; i < n; i++) {
            prev += diff[i];
            mn = min(mn, prev);
            mx = max(mx, prev);
        }
        long long up = mx + (lower - mn);
        return max(0LL, upper - up + 1);
    }
};