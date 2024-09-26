class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), pp = 0, p = 0;
        for(int i = n - 1; i >= 0; i--) {
            int temp = cost[i] + min(p, pp);
            pp = p;
            p = temp;
        }
        return min(pp, p);
    }
};