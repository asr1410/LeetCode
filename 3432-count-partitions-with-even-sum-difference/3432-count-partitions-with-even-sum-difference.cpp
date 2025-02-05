class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size(), ans = 0;
        tsum -= nums[0];
        for(int i = 1, t = nums[0]; i < n; i++) {
            ans += !(abs(tsum - t) & 1);
            t += nums[i];
            tsum -= nums[i];
        }
        return ans;
    }
};