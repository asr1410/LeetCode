class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, n = nums.size(), ans = 0;
        for(int j = 0; j < n; j++) {
            k -= nums[j] == 0;
            if(k >= 0) {
                ans = max(ans, j - i + 1);
            }
            while(k < 0) {
                k += nums[i++] == 0;
            }
        }
        return ans;
    }
};