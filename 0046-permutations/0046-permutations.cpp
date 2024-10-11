class Solution {
public:
    vector<vector<int>> ans;
    void permute(vector<int>& nums, vector<int>& temp, vector<int>& check) {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
        } else {
            for(int i = 0; i < nums.size(); i++) {
                if(check[i] == true) continue;
                temp.push_back(nums[i]);
                check[i] = true;
                permute(nums, temp, check);
                check[i] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<int> check(nums.size(), 0);
        permute(nums, temp, check);
        return ans;
    }
};