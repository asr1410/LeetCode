class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int ans = -1001, n = nums.size(), sum = 0;
        unordered_map<int, int> ump;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            ump[nums[i] * 2]++;
        }
        for(int i = 0; i < n; i++) {
            int t = sum - nums[i];
            if(ump[t] >= 2 or (ump[t] == 1 and (t != nums[i] * 2))) {
                ans = max(ans, nums[i]);
            }
        }
        return ans;
    }
};