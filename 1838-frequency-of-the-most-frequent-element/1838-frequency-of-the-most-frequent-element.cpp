class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long l = 0, n = nums.size(), total = 0, ans = 0;
        long long r = 0;

        while (r < n) {
            total += nums[r];
            long long cost = nums[r] * (r - l + 1) - total;

            while (cost > k) {
                total -= nums[l];
                l++;
                cost = nums[r] * (r - l + 1) - total;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
