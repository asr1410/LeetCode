class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), l = 0;
        for(int r = 0; r < n; r++) {
            k -= nums[r] == 0;
            if(k < 0) {
                k += nums[l] == 0;
                l++;
            }
        }
        return n - l;
    }
};