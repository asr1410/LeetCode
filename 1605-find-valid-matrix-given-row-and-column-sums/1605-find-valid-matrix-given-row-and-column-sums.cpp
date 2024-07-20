class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rsum, vector<int>& csum) {
        int rows = rsum.size();
        int cols = csum.size();
        vector<vector<int>> ans(rows, vector<int>(cols));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int minValue = min(rsum[row], csum[col]);
                ans[row][col] = minValue;
                rsum[row] -= minValue;
                csum[col] -= minValue;
            }
        }
        return ans;
    }
};
