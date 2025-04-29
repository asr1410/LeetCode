class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        for(int l = 0, r = 0; r < nums.size(); r++) {
            k -= nums[r] == mx;
            while(!k) {
                k += nums[l] == mx;
                l++;
            }
            ans += l;
        }
        return ans;
    }
};