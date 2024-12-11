class Solution {
public:
    int mark[500000] = {0};
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mark[nums[i] - k + 100000] += 1;
            mark[nums[i] + k + 100001] -= 1;
        }
        int ans = 0;
        for(int i = 0, s = 0; i < 500000; i++) {
            s += mark[i];
            ans = max(ans, s);
        }
        return ans;
    }
};