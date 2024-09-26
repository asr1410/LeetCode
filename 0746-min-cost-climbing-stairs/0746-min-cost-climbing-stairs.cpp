class Solution {
public:
    int helper(int i, vector<int>& cost, vector<int>& dp) {
        if(i >= cost.size()) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int otaken = cost[i] + helper(i + 1, cost, dp);
        int ttaken = cost[i] + helper(i + 2, cost, dp);
        return dp[i] = min(otaken, ttaken);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), pp = 0, p = 0;
        for(int i = n - 1; i >= 0; i--) {
            int otaken = cost[i] + p;
            int ttaken = cost[i] + pp;
            pp = p;
            p = min(otaken, ttaken);
        }
        return min(pp, p);
    }
};