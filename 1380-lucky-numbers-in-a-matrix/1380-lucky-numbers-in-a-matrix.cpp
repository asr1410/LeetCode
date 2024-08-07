class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> minInRow(m);
        vector<int> maxInCol(n);
        for (int i = 0; i < m; ++i) {
            minInRow[i] = mat[i][0];
            for (int j = 1; j < n; ++j) {
                minInRow[i] = min(minInRow[i], mat[i][j]);
            }
        }
        
        for (int j = 0; j < n; ++j) {
            maxInCol[j] = mat[0][j];
            for (int i = 1; i < m; ++i) {
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
