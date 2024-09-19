class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        bool row = false, col = false;
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    if(i == 0) row = true;
                    if(j == 0) col = true;
                    mat[i][0] = mat[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }
        if(row) {
            for(int i = 1; i < n; i++) {
                mat[0][i] = 0;
            }
        }
        if(col) {
            for(int i = 1; i < m; i++) {
                mat[i][0] = 0;
            }
        }
    }
};
