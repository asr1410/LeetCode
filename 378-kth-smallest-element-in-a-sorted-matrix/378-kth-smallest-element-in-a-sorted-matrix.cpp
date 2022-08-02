class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int, vector<int>, greater<int>> p;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                p.push(matrix[i][j]);
        while (--k)
            p.pop();
        return p.top();
    }
};