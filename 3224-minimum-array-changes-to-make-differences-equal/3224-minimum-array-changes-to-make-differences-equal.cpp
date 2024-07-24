class Solution {
public:
    int minChanges(vector<int>& nums, int K) {
        int n = nums.size();
        int f[K + 2];
        memset(f, 0, sizeof(f));
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            int d = abs(nums[i] - nums[j]);
            int mx = max({nums[i], K - nums[i], nums[j], K - nums[j]});
            f[0]++; f[d]--;
            f[d + 1]++;
            f[mx + 1]++;
        }

        int ans = n;
        for (int i = 0, now = 0; i <= K + 1; i++) {
            now += f[i];
            ans = min(ans, now);
        }
        return ans;
    }
};