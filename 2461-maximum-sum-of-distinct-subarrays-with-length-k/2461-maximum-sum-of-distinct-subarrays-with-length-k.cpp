class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        long long l = 0, ans = 0, temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            ump[nums[i]]++;
            temp += nums[i];
            if (i >= k - 1) {
                if (ump.size() == k) {
                    ans = max(ans, temp);
                }
                ump[nums[l]]--;
                if (ump[nums[l]] == 0) {
                    ump.erase(nums[l]);
                }
                temp -= nums[l];
                l++;
            }
        }
        return ans;
    }
};
