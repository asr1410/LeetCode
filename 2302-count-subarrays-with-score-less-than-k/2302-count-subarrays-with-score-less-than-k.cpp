class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long val = 0, ans = 0;
        int n = nums.size(), l = 0, r = 0;
        while(r < n) {
            val += nums[r];
            while(val * (r - l + 1) >= k) {
                val -= nums[l];
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
};