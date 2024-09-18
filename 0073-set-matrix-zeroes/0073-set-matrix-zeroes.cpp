class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), row = 0, col = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 and matrix[i][j] == 0) {
                    row = 1;
                }
                if(j == 0 and matrix[i][j] == 0) {
                    col = 1;
                }
                if(i != 0 and j != 0 and matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(row == 1 and i == 0) {
                    matrix[i][j] = 0;
                }
                if(col == 1 and j == 0) {
                    matrix[i][j] = 0;
                }
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};