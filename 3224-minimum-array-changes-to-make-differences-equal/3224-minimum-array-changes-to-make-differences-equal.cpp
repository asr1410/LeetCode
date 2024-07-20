class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mp(k + 1);
        vector<int> restr(k + 5);
        for (int i = 0; i < n - i - 1; i ++) {
            int a = nums[i], b = nums[n - i - 1];
            ++ mp[abs(a - b)];
            if (a > b)
                swap(a, b);
            ++ restr[max(k + 1 - a, b + 1)];
        }
        int ans = - n, cnt = 0;
        for (int i = 0; i <= k; i ++) {
            cnt -= restr[i];
            ans = max(ans, mp[i] + cnt);
        }
        return n / 2 - ans;
    }
};