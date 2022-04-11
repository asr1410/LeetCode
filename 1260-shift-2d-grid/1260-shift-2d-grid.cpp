class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int rowsize = grid.size();
        int colsize = grid[0].size();
        vector<vector<int>> ans(rowsize, vector<int>(colsize));
        for (int i = 0; i < rowsize; i++)
        {
            for (int j = 0; j < colsize; j++)
            {
                int newj = (j + k) % colsize;
                int newi = (i + (j + k) / colsize) % rowsize;
                ans[newi][newj] = grid[i][j];
            }
        }
        return ans;
    }
};