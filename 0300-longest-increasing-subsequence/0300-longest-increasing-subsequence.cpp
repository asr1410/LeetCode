class Solution {
public:
    int helper(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i == nums.size()) {
            return 0;
        }
        if(dp[i][j + 1] != -1) {
            return dp[i][j + 1];
        }
        int ntaken = helper(i + 1, j, nums, dp);
        int taken = (j == -1 or nums[i] > nums[j]) ? 1 + helper(i + 1, i, nums, dp) : 0;
        return dp[i][j + 1] = max(ntaken, taken);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(0, -1, nums, dp);
    }
};