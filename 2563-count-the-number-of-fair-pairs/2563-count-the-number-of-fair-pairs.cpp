class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int low = lower - nums[i], high = upper - nums[i];
            auto lowerBound = lower_bound(nums.begin() + i + 1, nums.end(), low);
            auto upperBound = upper_bound(nums.begin() + i + 1, nums.end(), high);
            ans += distance(lowerBound, upperBound);
        }
        return ans;
    }
};
