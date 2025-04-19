class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int lb = lower - nums[i];
            int ub = upper - nums[i];
            int l = lower_bound(nums.begin() + i + 1, nums.end(), lb) - nums.begin();
            int r = upper_bound(nums.begin() + i + 1, nums.end(), ub) - nums.begin();
            ans += r - l;
        }

        return ans;
    }
};
