class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> minInRow(m, INT_MAX);
        vector<int> maxInCol(n, INT_MIN);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                minInRow[i] = min(minInRow[i], mat[i][j]);
            }
        }
        
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                maxInCol[j] = max(maxInCol[j], mat[i][j]);
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == minInRow[i] && mat[i][j] == maxInCol[j]) {
                    ans.push_back(mat[i][j]);
                }
            }
        }
        
        return ans;
    }
};
