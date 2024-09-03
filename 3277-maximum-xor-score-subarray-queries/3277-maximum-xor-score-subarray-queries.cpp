class Solution {
public:
  pair<int,int> solve(int i,int j, vector<vector<pair<int,int>>>&dp,vector<int>&nums)
  {
 if(i==j)return {nums[i],nums[i]};
            if(dp[i][j]!=make_pair(-1,-1))return dp[i][j];
            pair<int,int> left=solve(i,j-1,dp,nums);
            pair<int,int> down=solve(i+1,j,dp,nums);
            int window=left.second^down.second;
            int maxi=max({window,left.first,down.first});
   return dp[i][j]={maxi,window};
  }
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {     
        int n=nums.size();
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(n,{-1,-1}));

     vector<int>res;
     for(auto&i:queries)
     {
          res.push_back(solve(i[0],i[1],dp,nums).first);
     }
   
     return res;
 }
};