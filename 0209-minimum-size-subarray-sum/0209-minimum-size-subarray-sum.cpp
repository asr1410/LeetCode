class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = n + 1;
        for(int l = 0, r = 0; r < n; r++) {
            target -= nums[r];
            while(target <= 0) {
                ans = min(ans, r - l + 1);
                target += nums[l];
                l++;
            }
        }
        return ans % (n + 1);
    }
};