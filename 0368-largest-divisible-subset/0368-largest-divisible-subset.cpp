class Solution {
public:
    vector<int> dp;
    vector<int> parent;
    
    int helper(int idx, vector<int>& nums) {
        if (idx == nums.size()) return 0;
        if (dp[idx] != -1) return dp[idx];
        
        int maxLength = 1;
        parent[idx] = -1;
        
        for (int prev = 0; prev < idx; prev++) {
            if (nums[idx] % nums[prev] == 0) {
                int subLength = 1 + dp[prev];
                if (subLength > maxLength) {
                    maxLength = subLength;
                    parent[idx] = prev;
                }
            }
        }
        
        return dp[idx] = maxLength;
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        dp.resize(n, -1);
        parent.resize(n, -1);
        
        int maxIdx = 0;
        for (int i = 0; i < n; i++) {
            if (helper(i, nums) > helper(maxIdx, nums)) {
                maxIdx = i;
            }
        }
        
        vector<int> result;
        while (maxIdx != -1) {
            result.push_back(nums[maxIdx]);
            maxIdx = parent[maxIdx];
        }
        
        return result;
    }
};