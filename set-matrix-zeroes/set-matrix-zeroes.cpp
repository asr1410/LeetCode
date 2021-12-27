class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                q.push({i, j});
            }
        }
    }
    int m = matrix.size();
    int n = matrix[0].size();
    // showQueue(q);
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        for (int k = 0; k < m; k++)
        {
            matrix[k][j] = 0;
        }
        for (int k = 0; k < n; k++)
        {
            matrix[i][k] = 0;
        }
        q.pop();
    }
    }
};