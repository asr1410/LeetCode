class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long zc1 = 0, zc2 = 0, tsum1 = 0, tsum2 = 0;
        for(const int& num : nums1) {
            tsum1 += num;
            zc1 += num == 0;
        }

        for(const int& num : nums2) {
            tsum2 += num;
            zc2 += num == 0;
        }
        if(zc1 == 0 and zc2 == 0) {
            return tsum1 == tsum2 ? tsum1 : -1;
        }
        if(zc1 == 0) {
            return tsum1 >= tsum2 + zc2 ? tsum1 : -1;
        }
        if(zc2 == 0) {
            return tsum2 >= tsum1 + zc1 ? tsum2 : -1;
        }
        return max(tsum1 + zc1, tsum2 + zc2);
    }
};