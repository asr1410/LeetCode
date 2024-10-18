class Solution {
public:
    int me = 0;
    int ans = 0;
    void helper(int i, int curr, vector<int>& nums) {
        if(i < 0) {
            me = max(me, curr);
            return;
        }
        helper(i - 1, curr, nums);
        helper(i - 1, curr | nums[i], nums);
    }
    
    void answer(int i, int curr, vector<int>& nums) {
        if(i < 0) {
            ans += (me == curr);
            return;
        }
        answer(i - 1, curr, nums);
        answer(i - 1, curr | nums[i], nums);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        helper(nums.size() - 1, 0, nums);
        answer(nums.size() - 1, 0, nums);
        return ans;
    }
};