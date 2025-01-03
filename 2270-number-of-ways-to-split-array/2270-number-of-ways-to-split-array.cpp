class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long tsum = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = 0, n = nums.size() - 1;
        long long lsum = 0;
        for(int i = 0; i < n; i++) {
            lsum += nums[i];
            tsum -= nums[i];
            if(lsum >= tsum) {
                ans++;
            }
        }
        return ans;
    }
};