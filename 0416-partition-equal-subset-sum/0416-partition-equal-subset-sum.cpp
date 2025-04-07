class Solution {
public:
    vector<vector<int>> dp;
    bool helper(int i, int sum, vector<int>& nums) {
        if(sum < 0) {
            return false;
        }
        if(sum == 0) {
            return true;
        }
        if(i == nums.size() - 1) {
            return sum == nums.back();
        }
        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }
        return dp[i][sum] = helper(i + 1, sum - nums[i], nums) or helper(i + 1, sum, nums);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) {
            return false;
        }
        int n = nums.size();
        dp.resize(n, vector<int> (sum / 2 + 1, -1));
        return helper(0, sum / 2, nums);
    }
};