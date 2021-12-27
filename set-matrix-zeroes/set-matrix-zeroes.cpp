class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool cornerrow = false;
        bool cornercol = false;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                if (i == 0)
                    cornerrow = true;
                else if(j == 0)
                    cornercol = true;
                else
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for (int i = matrix.size() - 1; i >= 0; i--)
    {
        for (int j = matrix[i].size() - 1; j >= 0; j--)
        {
            if(i == 0 && cornerrow == true)
                matrix[i][j] = 0;
            else if(j == 0 && cornercol == true)
                matrix[i][j] = 0;
            else if (matrix[i][0] == 0 or matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (cornerrow or cornercol)
    {
        matrix[0][0] = 0;
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 0, 0, 1}};
    for (auto &&i : matrix)
    {
        for (auto &&i : i)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    setZeroes(matrix);
    for (auto &&i : matrix)
    {
        for (auto &&i : i)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
    }
};