class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, n = nums.size(), ans = 0;
        for(int j = 0; j < n; j++) {
            k -= nums[j] == 0;
            k += k < 0 and nums[i++] == 0;
        }
        return n - i;
    }
};