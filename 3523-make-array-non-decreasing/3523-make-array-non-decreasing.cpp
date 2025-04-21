class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        for(int i = 1, prev = nums[0]; i < n; i++) {
            prev = max(prev, nums[i]);
            ans += prev == nums[i];
        }
        return ans;
    }
};