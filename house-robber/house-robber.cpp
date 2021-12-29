class Solution {
public:
    int rob(vector<int>& nums) {
        int cur = 0;
        int prev = 0;
        int prev2 = 0;
        for(int n : nums)
        {
            cur = max(prev, prev2 + n);
            prev2 = prev;
            prev = cur;
        }
        return cur;
    }
};