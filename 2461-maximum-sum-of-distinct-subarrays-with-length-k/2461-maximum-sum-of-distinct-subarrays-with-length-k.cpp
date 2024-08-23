class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> uset;
        long long sum = 0, ans = 0;
        for(int i = 0, j = 0; i < nums.size(); i++) {
            while(uset.size() == k or (uset.empty() == false and uset.find(nums[i]) != uset.end())) {
                uset.erase(nums[j]);
                sum -= nums[j];
                j++;
            }
            sum += nums[i];
            uset.emplace(nums[i]);
            if(uset.size() == k) {
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};