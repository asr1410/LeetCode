class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& range) {
        sort(range.begin(), range.end());
        vector<vector<int>> ans;
        ans.push_back(range[0]);
        for(int i = 1; i < range.size(); i++) {
            if(ans[ans.size() - 1][1] >= range[i][0]) {
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], range[i][1]);
            } else {
                ans.push_back(range[i]);
            }
        }
        return ans;
    }
};