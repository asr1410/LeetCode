class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>&ans, vector<int>& temp, int index) {
        if(index == nums.size()) {
            ans.push_back(temp);
        } else {
            temp.push_back(nums[index]);
            helper(nums, ans, temp, index + 1);
            temp.pop_back();
            helper(nums, ans, temp, index + 1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, ans, temp, 0);
        return ans;
    }
};