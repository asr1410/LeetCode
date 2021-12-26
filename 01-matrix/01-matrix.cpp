class Solution {
public:
    bool check(int i, int j, int m, int n)
{
    if (i < 0 || j < 0 || i >= m || j >= n)
        return false;
    return true;
}
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 0)
                q.push({i, j});
            else
                mat[i][j] = -1;
        }
    }
    int m = mat.size();
    int n = mat[0].size();
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        if (check(i - 1, j, m, n) && mat[i - 1][j] == -1)
        {
            q.push({i - 1, j});
            mat[i - 1][j] = mat[i][j] + 1;
        }
        if (check(i + 1, j, m, n) && mat[i + 1][j] == -1)
        {
            q.push({i + 1, j});
            mat[i + 1][j] = mat[i][j] + 1;
        }
        if (check(i, j + 1, m, n) && mat[i][j + 1] == -1)
        {
            q.push({i, j + 1});
            mat[i][j + 1] = mat[i][j] + 1;
        }
        if (check(i, j - 1, m, n) && mat[i][j - 1] == -1)
        {
            q.push({i, j - 1});
            mat[i][j - 1] = mat[i][j] + 1;
        }
        q.pop();
    }

    return mat;
}
};