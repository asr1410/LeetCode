class Solution {
public:
    bool canDo(long long d, long long mh, std::vector<int>& wt) {
        long long wd = 0;
        for(int w : wt) {
            wd += static_cast<long long>(sqrt(d / w * 2 + 0.25) - 0.5);
        }
        return wd >= mh;
    }
    
    long long minNumberOfSeconds(int mh, std::vector<int>& wt) {
        long long l = 0, r = LLONG_MAX, ans = -1;
        while(l <= r) {
            long long m = (l + r) / 2;
            if(canDo(m, mh, wt)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
