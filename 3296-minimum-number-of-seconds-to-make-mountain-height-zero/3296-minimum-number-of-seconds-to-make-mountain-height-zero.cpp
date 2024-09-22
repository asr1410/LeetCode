class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& wt) {
        long long l = 1, r = 100000000000LL * mountainHeight / wt.size();
        while (l < r) {
            long long m = (l + r) / 2, h = transform_reduce(begin(wt), end(wt), 0LL, plus{}, [&](int t){
                return (long long)(sqrt(m / t * 2 + 0.25) - 0.5);
            });
            if (h < mountainHeight)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};