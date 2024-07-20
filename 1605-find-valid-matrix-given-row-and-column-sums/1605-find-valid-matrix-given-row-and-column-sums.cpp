class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rsize = rowSum.size(), csize = colSum.size();
        vector<vector<int>> ans(rsize, vector<int>(csize));
        for(int row = 0, col = 0; row < rsize and col < csize;) {
            int mn = ans[row][col] = min(rowSum[row], colSum[col]);
            row += ((rowSum[row] -= mn) == 0);
            col += ((colSum[col] -= mn) == 0);
        }
        return ans;
    }
};