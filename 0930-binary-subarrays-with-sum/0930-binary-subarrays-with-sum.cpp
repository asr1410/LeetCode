class Solution {
public:
    int atmost(vector<int> &nums, int goal) {
        if(goal < 0) {
            return 0;
        }
        int ans = 0;
        for(int l = 0, r = 0, count = 0; r < nums.size(); r++) {
            count += nums[r];
            while(count > goal) {
                count -= nums[l];
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};