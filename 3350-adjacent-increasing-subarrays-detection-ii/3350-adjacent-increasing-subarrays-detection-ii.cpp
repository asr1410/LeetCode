class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int f = 1, s = 0, n = nums.size(), ans = 0, l = 1, r = 1;
        while( l < n and nums[l - 1] < nums[l]) {
            l++;
            f++;
        }
        ans = max(ans, max(f / 2, max(s / 2, min(f, s))));
        while(l < n) {
            s = 1;
            l++;
            while(l < n and nums[l - 1] < nums[l]) {
                l++;
                s++;
            }
            ans = max(ans, max(f / 2, max(s / 2, min(f, s))));
            f = s;
        }
        return ans;
    }
};