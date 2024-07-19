class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        unordered_set<int> uset;
        for(int i = 0; i < mat.size(); i++) {
            int mn = mat[i][0];
            for(int j = 1; j < mat[0].size(); j++) {
                mn = min(mn, mat[i][j]);
            }
            uset.insert(mn);
        }
        vector<int> ans;
        for(int j = 0; j < mat[0].size(); j++) {
            int mx = mat[0][j];
            for(int i = 1; i < mat.size(); i++) {
                mx = max(mx, mat[i][j]);
            }
            if(uset.count(mx)) {
                ans.push_back(mx);
            }
        }
        return ans;
    }
};