class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int j = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] != 0 and nums[i] == nums[i + 1]) {
                ans[j] = nums[i] * 2;
                j++;
                nums[i + 1] = 0;
            } else if(nums[i] != 0) {
                ans[j] = nums[i];
                j++;
            }
        }
        ans[j] = nums[n - 1];
        return ans;
    }
};