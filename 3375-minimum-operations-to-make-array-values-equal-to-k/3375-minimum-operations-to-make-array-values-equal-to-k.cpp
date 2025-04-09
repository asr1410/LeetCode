class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mn = *min_element(nums.begin(), nums.end());
        if(mn < k) {
            return -1;
        }
        vector<int> cnt(101, 0);
        for(int num : nums) {
            cnt[num] = 1;
        }
        int ans = accumulate(cnt.begin(), cnt.end(), 0);
        return mn == k ? ans - 1 : ans;
    }
};