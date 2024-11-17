class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
int l = 0, r = 0, n = nums.size();
        int sum = 0, ans = 1e9 + 7;
        while(r < n) {
            sum += nums[r];
            while(l < r and sum - nums[l] >= k) {
                sum -= nums[l];
                l++;
            }
            if(sum >= k) {
                ans = min(ans, r - l + 1);
            }
            r++;
        }
        while(l < r) {
            sum -= nums[l];
            l++;
            if(sum >= k) {
                ans = min(ans, r - l);
            }
        }
        return ans == 1e9 + 7 ? 0 : ans;
    }
};