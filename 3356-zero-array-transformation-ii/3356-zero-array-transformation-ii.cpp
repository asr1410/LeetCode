class Solution {
public:
    bool check(int m, vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for(int i = 0; i <= m; i++) {
            pre[queries[i][0]] -= queries[i][2];
            pre[queries[i][1] + 1] += queries[i][2];
        }
        for(int i = 1; i < n; i++) {
            pre[i] += pre[i - 1];
        }
        // cout << m << endl;
        // for(int i = 0; i < n; i++) {
        //     cout << pre[i] << " ";
        // }
        // cout << endl;
        for(int i = 0; i < n; i++) {
            if(nums[i] + pre[i] > 0) {
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if(accumulate(nums.begin(), nums.end(), 0LL) == 0LL) {
            return 0;
        }
        int l = 0, r = queries.size();
        while(l < r) {
            int m = (l + r) >> 1;
            if(check(m, nums, queries)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l + 1 > queries.size() ? -1 : l + 1;
    }
};