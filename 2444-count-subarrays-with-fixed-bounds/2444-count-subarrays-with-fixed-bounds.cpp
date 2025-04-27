class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0, mnk = -1, mxk = -1, k = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == minK) {
                mnk = i;
            }
            if(nums[i] == maxK) {
                mxk = i;
            }
            if(nums[i] < minK or nums[i] > maxK) {
                k = i;
            }
            ans += max(0LL, min(mnk, mxk) - k);
        }
        return ans;
    }
};