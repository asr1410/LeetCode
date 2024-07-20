class Solution {
public:
    int n, a[100005], b1[100005], b2[100005];
    int minChanges(vector<int>& nums, int k) {
        n = nums.size();
        for(int i = 1; i <= n; ++i) a[i] = nums[i - 1];
        for(int i = 1; i <= n / 2; ++i) b1[abs(a[i] - a[n - i + 1])] += 1;
        for(int i = 1; i <= n / 2; ++i){
            int m1 = std::max(k - a[i], a[i] - 0), m2 = std::max(k - a[n - i + 1], a[n - i + 1] - 0);
            ++b2[std::max(m1, m2)];
        }
        for(int i = 1; i <= k; ++i) b2[i] += b2[i - 1];
        int ans = 1e9;
        for(int i = 0; i <= k; ++i){
            int tmp = n / 2 - b1[i];
            if(i >= 1) ans = std::min(ans, tmp + b2[i - 1]);
            else ans = std::min(ans, tmp);
        }
        return ans;
    }
};