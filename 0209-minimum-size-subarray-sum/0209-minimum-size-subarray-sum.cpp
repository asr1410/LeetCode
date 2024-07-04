class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;
        for(int l = 0, r = 0, sum = 0; r < n; r++) {
            sum += nums[r];
            while(sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }

        }
        return ans == n + 1 ? 0 : ans;
    }
};