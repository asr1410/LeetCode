class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> count(101);
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            if(count[nums[i]] == 2) {
                ans.push_back(nums[i]);
                if(ans.size() == 2) {
                    return ans;
                }
            }
        }
        return ans;
    }
};