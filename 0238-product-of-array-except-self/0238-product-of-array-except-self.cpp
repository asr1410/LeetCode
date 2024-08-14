class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int zcount = 0, n = nums.size(), zindex = 0, mul = 1;
      for(int i = 0; i < n; i++) {
        zcount += nums[i] == 0;
        zindex = nums[i] == 0 ? i : zindex;
        mul *= nums[i] == 0 ? 1 : nums[i];
        if(zcount > 1) {
          return vector<int> (n, 0);
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