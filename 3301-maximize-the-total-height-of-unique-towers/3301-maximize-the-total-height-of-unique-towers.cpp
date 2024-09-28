class Solution {
public:
    long long maximumTotalSum(vector<int>& mh) {
        sort(begin(mh), end(mh));
        int n = mh.size();
        long long ans = mh[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            if(mh[i] >= mh[i + 1]) {
                mh[i] -= (mh[i] - mh[i + 1] + 1);
                if(mh[i] <= 0) {
                    return -1;
                }
                ans += mh[i];
            } else {
                ans += mh[i];
            }
        }
        return ans;
    }
};