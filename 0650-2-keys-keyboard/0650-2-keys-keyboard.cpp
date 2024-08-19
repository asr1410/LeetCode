class Solution {
public:
    int helper(int num, int copy, int target) {
        if(num == target) {
            return 0;
        }
        int cpmove = num + num <= target ? 2 + helper(num + num, num, target) : 1e9;
        int pmove = num + copy <= target ? 1 + helper(num + copy, copy, target) : 1e9;
        return min(cpmove, pmove);
    }
    int minSteps(int target) {
        if(target == 1) {
            return 0;
        }
        int num = 1, copy = 1;
        return helper(num, copy, target) + 1;
    }
};