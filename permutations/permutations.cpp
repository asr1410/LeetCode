class Solution {
public:
    void permute(vector<int>&nums,vector<vector<int>>&ans, int l, int n)
    {
        if(l == n)
        ans.push_back(nums);
        for(int i = l; i<=n; i++)
        {
            swap(nums[l], nums[i]);
            permute(nums,ans,l+1,n);
            swap(nums[l],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permute(nums,ans,0,nums.size()-1);
        return ans;
    }
};