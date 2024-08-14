class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int zcount = 0, n = nums.size(), zindex;
      for(int i = 0; i < n; i++) {
        if(nums[i] == 0) {
          zcount++,
          zindex = i;
        }
        if(zcount > 1) {
          return vector<int> (n, 0);
        }
      }
      int mul = 1;
      for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
          mul *= nums[i];
        }
      }
      if(zcount == 1) {
        vector<int> ans(n, 0);
        ans[zindex] = mul;
        return ans;
      }
      vector<int> ans(n, mul);
      for(int i = 0; i < n; i++) {
        ans[i] /= nums[i];
      }
      return ans;
    }
};