class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> pre(n, 0);
        for(int i = 1; i < n; i++) {
            pre[i] = (abs(nums[i - 1] - nums[i]) > maxDiff);
        }
        // for(int i = 0; i < n; i++) {
        //     cout << pre[i] << " ";
        // }
        // cout << endl;
        for(int i = 1; i < n; i++) {
            pre[i] += pre[i - 1];
        }
        // for(int i = 0; i < n; i++) {
        //     cout << pre[i] << " ";
        // }
        // cout << endl;
        int t = queries.size();
        vector<bool> ans(t, false);
        for(int i = 0; i < t; i++) {
            ans[i] = (pre[queries[i][1]] - pre[queries[i][0]]) == 0;
        }
        return ans;
    }
};