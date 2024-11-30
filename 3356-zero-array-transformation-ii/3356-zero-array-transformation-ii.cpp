class Solution {
public:
    bool possible(int k, vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> mark(n + 1, 0);
        for(int i = 0; i <= k; i++) {
            long long si = queries[i][0], ei = queries[i][1], val = queries[i][2];
            mark[si] -= val;
            mark[ei + 1] += val;
        }
        for(int i = 1; i < n; i++) {
            mark[i] += mark[i - 1];
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] + mark[i] > 0) {
                return false;
            }
        }
        return true;
    }
    
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if(accumulate(nums.begin(), nums.end(), 0LL) == 0) {
            return 0;
        }
        int n = queries.size(), l = 0, r = n - 1, ans = -1;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(possible(m, nums, queries)) {
                ans = m + 1;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
