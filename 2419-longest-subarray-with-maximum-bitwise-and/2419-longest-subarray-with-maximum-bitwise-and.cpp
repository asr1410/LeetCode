class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0, count = 0; i < nums.size(); i++) {
            if(nums[i] == mx) {
                count++;
                ans = max(ans, count);
            } else {
                count = 0;
            }
        }
        return ans;
    }
};