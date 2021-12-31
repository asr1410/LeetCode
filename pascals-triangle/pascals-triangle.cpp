class Solution {
public:
    vector<vector<int>> generate(int row) {
        vector<vector<int>> ans{{1}};
        for(int i = 0; i < row - 1; i++)
        {
            vector<int> nums(i+2);
            for(int j = 0; j < i + 1; j++)
            {
                nums[j] += ans[i][j];
                nums[j + 1] +=ans[i][j];
            }
            ans.push_back(nums);
        }
        return ans;
    }
};