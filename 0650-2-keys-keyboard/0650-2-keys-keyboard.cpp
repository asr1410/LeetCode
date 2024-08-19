class Solution {
public:
    int helper(int num, int copy, int target, vector<vector<int>>& dp) {
        if(num == target) {
            return 0;
        }
        if(dp[num][copy] != -1) {
            return dp[num][copy];
        }
        int cpmove = num + num <= target ? 2 + helper(num + num, num, target, dp) : 1e9;
        int pmove = num + copy <= target ? 1 + helper(num + copy, copy, target, dp) : 1e9;
        return dp[num][copy] = min(cpmove, pmove);
    }
    int minSteps(int target) {
        if(target == 1) {
            return 0;
        }
        vector<vector<int>> dp(target + 1, vector<int> (target + 1, -1));
        int num = 1, copy = 1;
        return helper(num, copy, target, dp) + 1;
    }
};