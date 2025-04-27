class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        int n = nums.size();
        for(int& num : nums) {
            num = (num % mod == k) ? 1 : 0;
        }
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        
        long long ans = 0;
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % mod;
            int target = (sum - k + mod) % mod;
            ans += prefixCount[target];
            prefixCount[sum]++;
        }
        return ans;
    }
};