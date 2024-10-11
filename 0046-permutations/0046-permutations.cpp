class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& permute, int left, int right) {
        if(left == right) {
            permute.push_back(nums);
        }
        else {
            for(int i = left; i <= right; i++) {
                swap(nums[left], nums[i]);
                helper(nums, permute, left + 1, right);
                swap(nums[left], nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permute;
        helper(nums, permute, 0, nums.size() - 1);
        return permute;
    }
};