class Solution {
public:
    void setZeroes(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> ans = mat;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 0)
            {
                int trow = row;
                int tcol = col;
                while (trow--)
                {
                    if (ans[trow][j])
                        ans[trow][j] = 0;
                }
                while (tcol--)
                {
                    if (ans[i][tcol])
                        ans[i][tcol] = 0;
                }
            }
        }
    }
    mat = ans;
    ans.clear();
}
};