class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int numRows = rowSum.size();
        int numCols = colSum.size();
        vector<vector<int>> ans(numRows, vector<int>(numCols));
        
        for (int row = 0, col = 0; row < numRows && col < numCols;) {
            int mn = ans[row][col] = min(rowSum[row], colSum[col]);
            row += (rowSum[row] -= mn) == 0;
            col += (colSum[col] -= mn) == 0;
        }
        
        return ans;
    }
};
