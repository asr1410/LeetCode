class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end(), greater<int>());
        sort(vc.begin(), vc.end(), greater<int>());
        hc.push_back(0);
        vc.push_back(0);
        long long hsum = accumulate(hc.begin(), hc.end(), 0);
        long long vsum = accumulate(vc.begin(), vc.end(), 0);
        long long total = 0, i = 0, j = 0;
        while(i < m and j < n) {
            if(hc[i] > vc[j]) {
                total += hc[i] + vsum;
                hsum -= hc[i];
                i++;
            } else {
                total += vc[j] + hsum;
                vsum -= vc[j];
                j++;
            }
        }
        return total;
    }
};