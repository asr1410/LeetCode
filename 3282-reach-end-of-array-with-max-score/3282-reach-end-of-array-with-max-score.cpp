class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp{0};
        for(int i = 1, mi = 0; i < n; i++) {
            dp.push_back((i - mi) * 1LL * nums[mi] + dp[mi]);
            if(nums[i] > nums[mi]) {
                mi = i;
            }
        }
        return dp[n - 1];
    }
};