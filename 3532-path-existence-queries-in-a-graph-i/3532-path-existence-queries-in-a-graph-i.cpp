class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> pre;
        pre.reserve(n);
        pre.push_back(0);
        for(int i = 1; i < n; i++) {
            pre.push_back((abs(nums[i - 1] - nums[i]) > maxDiff) +  pre[i - 1]);
        }
        int t = queries.size();
        vector<bool> ans;
        ans.reserve(t);
        for(int i = 0; i < t; i++) {
            ans.push_back((pre[queries[i][1]] - pre[queries[i][0]]) == 0);
        }
        return ans;
    }
};