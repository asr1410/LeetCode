class Solution {
public:
    int dp[1002][1002];
    
    int helper(int curr, int prev, vector<int>& nums) {
        if(curr == nums.size()) {
            return 0;
        }
        
        if(dp[curr][prev+1] != -1) {  // Shift prev by +1 since prev can be -1
            return dp[curr][prev+1];
        }
        
        int taken = 0, ntaken = 0;
        
        if(prev == -1 || nums[curr] % nums[prev] == 0) {
            taken = 1 + helper(curr + 1, curr, nums);
        }
        
        ntaken = helper(curr + 1, prev, nums);
        
        return dp[curr][prev+1] = max(taken, ntaken);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        memset(dp, -1, sizeof(dp));
        
        int n = nums.size();
        int maxLen = helper(0, -1, nums);
        
        vector<int> result;
        int curr = 0, prev = -1;
        
        while(curr < n) {
            if(prev == -1 || nums[curr] % nums[prev] == 0) {
                int taken = 1 + helper(curr + 1, curr, nums);
                if(taken == helper(curr, prev, nums)) {
                    result.push_back(nums[curr]);
                    prev = curr;
                }
            }
            curr++;
        }
        
        return result;
    }
};