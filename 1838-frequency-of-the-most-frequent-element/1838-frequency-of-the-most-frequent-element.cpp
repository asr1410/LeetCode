class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long l = 0, sum = 0, ans = 0, r = 0, n = nums.size();
        while (r < n) {
            sum += nums[r];
            while (nums[r] * (r - l + 1) - sum > k) {
                sum -= nums[l++];
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
