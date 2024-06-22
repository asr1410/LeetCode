class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, ans = 0;
        for(int j = 0; j < n; j++) {
            k -= nums[j] & 1;
            while(k < 0) {
                k += nums[i++] & 1;
            }
            ans += j - i + 1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};