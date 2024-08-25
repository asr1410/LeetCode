class Solution {
public:
    vector<int> getFinalState(vector<int> nums, int k, int multiplier) {
        int n = nums.size();
        while(k--) {
            int idx = -1;
            for(int i = 0, mn = INT_MAX; i < n; i++) {
                if(nums[i] < mn) {
                    mn = nums[i];
                    idx = i;
                }
            }
            nums[idx] *= multiplier;
        }
        return nums;
    }
};