class Solution {
public:
    int climbStairs(int n) {
        int prev = 0;
        int next = 1;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum = prev + next;
            prev = next;
            next = sum;
        }
        return sum;
    }
};