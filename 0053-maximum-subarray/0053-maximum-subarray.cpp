class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = nums[0], temp = ans;
      for(int i = 1; i < n; i++) {
        if(temp >= 0) {
          temp += nums[i];
          ans = max(ans, temp);
        } else {
          temp = nums[i];
          ans = max(ans, temp);
        }
      }
      return ans;
    }
};