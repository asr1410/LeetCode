class Solution {
public:
    int atmost(vector<int> &nums, int goal) {
        if(goal < 0) return 0;
        int ans = 0;
        for(int l = 0, r = 0; r < nums.size(); r++) {
            goal -= nums[r];
            while(goal < 0) {
                goal += nums[l++];
            }
            ans += r - l + 1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};