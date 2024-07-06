class Solution {
public:
    int atmost(vector<int> &nums, int k) {
        int ans = 0, n = nums.size();
        for(int l = 0, r = 0, count = 0; r < n; r++) {
            count += nums[r] & 1; // Increment count if nums[r] is odd (nums[r] & 1 evaluates to 1 for odd numbers)
            while(count > k) {
                count -= nums[l] & 1; // Decrement count if nums[l] is odd
                l++;
            }
            // If count is less than or equal to k, add the number of valid subarrays ending at r
            ans += r - l + 1;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};