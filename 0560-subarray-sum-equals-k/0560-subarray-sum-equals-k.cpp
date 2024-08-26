class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        int sum = 0;
        mp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int remove = sum - k;
            count += mp[remove];
            mp[sum] += 1;
        }
        return count;
    }
};