class Solution {
public:
    vector<vector<int>> ans;
    void helper(int l, int r, vector<int>& nums) {
        if(l == r) {
            ans.emplace_back(nums);
        } else {
            for(int i = l; i <= r; i++) {
                swap(nums[l], nums[i]);
                helper(l + 1, r, nums);
                swap(nums[l], nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(0, nums.size() - 1, nums);
        return ans;
    }
};