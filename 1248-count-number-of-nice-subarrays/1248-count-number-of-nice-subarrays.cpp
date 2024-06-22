class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        int ans = 0, n = nums.size(), i = 0;
        for(int j = 0; j < n; j++) {
            k -= nums[j] % 2;
            while(k < 0) {
                k += nums[i++] % 2;
            }
            ans += j - i + 1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};