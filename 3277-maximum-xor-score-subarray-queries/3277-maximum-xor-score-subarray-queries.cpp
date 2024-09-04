class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        
        for(int i = 2; i <= n; i++) {
            for(int l = 0; l + i - 1 < n; l++) {
                int r = l + i - 1;
                dp[l][r] = dp[l][r - 1] ^ dp[l + 1][r];
            }
        }
        
        for(int i = 2; i <= n; i++) {
            for(int l = 0; l + i - 1 < n; l++) {
                int r = l + i - 1;
                dp[l][r] = max(dp[l][r], max(dp[l][r - 1], dp[l + 1][r]));
            }
        }
        
        vector<int> ans;
        for(auto q : queries) {
            ans.push_back(dp[q[0]][q[1]]);
        }
        return ans;
    }
};