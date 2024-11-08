class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> nnums(n, 0);
        nnums[0] = nums[0];
        for(int i = 1; i < n; i++) {
            nnums[i] = nnums[i - 1] ^ nums[i];
        }
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            int tnum = 0;
            int gnum = nnums[i];
           for(int j = 0; j < maximumBit; j++) {
               if(((gnum >> j) & 1) == 0) {
                   tnum = tnum | (1 << j);
               }
           }
            ans[i]  = tnum;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};