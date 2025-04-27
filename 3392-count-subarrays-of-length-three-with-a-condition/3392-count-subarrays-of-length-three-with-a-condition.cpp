class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size() - 1, ans = 0;
        for(int i = 1; i < n; i++) {
            ans += (nums[i - 1] + nums[i + 1]) * 2 == nums[i];
        }
        return ans;
    }
};