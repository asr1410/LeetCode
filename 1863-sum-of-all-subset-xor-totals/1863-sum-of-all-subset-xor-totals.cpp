class Solution {
public:
    int ans = 0;
    void helper(int i, vector<int>& nums, int val) {
        if(i == nums.size()) {
            ans += val;
            return;
        }
        helper(i + 1, nums, val ^ nums[i]);
        helper(i + 1, nums, val);
    }
    int subsetXORSum(vector<int>& nums) {
        helper(0, nums, 0);
        return ans;
    }
};