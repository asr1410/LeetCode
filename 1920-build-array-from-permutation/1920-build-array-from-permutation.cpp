class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(const int& num : nums) {
            ans.emplace_back(nums[num]);
        }
        return ans;
    }
};