class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0, n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // If we can't reach this position, return false
            if (i > farthest) return false;
            
            // Update the farthest position reachable
            farthest = max(farthest, i + nums[i]);
            
            // If we can reach or surpass the last index, return true
            if (farthest >= n - 1) return true;
        }
        
        return false;
    }
};
