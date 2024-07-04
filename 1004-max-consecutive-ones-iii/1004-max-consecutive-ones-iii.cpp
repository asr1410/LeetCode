class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, n = nums.size();
        for(int r = 0; r < n; r++) {
            k -= nums[r] == 0;
            k += k < 0 and nums[l++] == 0;
        }
        return n - l;
    }
};