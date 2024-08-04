class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int mod = 1e9 + 7;
        multiset<int> s;
        for(int i = 0; i < n; i++) {
            int tsum = 0;
            for(int j = i; j < n; j++) {
                tsum += nums[j];
                s.emplace(tsum);
            }
        }

        auto it = s.begin();
        int ans = 0;
        for(int i = 1; i < left; i++) {
            ++it;
        }
        for(int i = left; i <= right; i++) {
            ans = (ans + *it) % mod;
            ++it;
        }
        return ans;
    }
};
