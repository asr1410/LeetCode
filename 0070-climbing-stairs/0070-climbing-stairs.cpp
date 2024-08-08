class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1, prev1 = 2;
        if(n == 1) {
            return prev2;
        }
        for(int i = 3; i <= n; i++) {
            int curri = prev1 + prev2;
            prev2 = prev1;
            prev1 = curri;
        }
        return prev1;
    }
};