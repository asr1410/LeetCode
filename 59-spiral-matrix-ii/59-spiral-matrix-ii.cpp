class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> m(n, vector<int>(n));

        int i = 0, j = 0, c = 1;
        while (c <= n * n)
        {
            while (j < n and !m[i][j])
            {
                m[i][j++] = c++;
            }
            j--, i++;
            while (i < n and !m[i][j])
            {
                m[i++][j] = c++;
            }
            i--, j--;
            while (j >= 0 and !m[i][j])
            {
                m[i][j--] = c++;
            }
            i--, j++;
            while (i >= 0 and !m[i][j])
            {
                m[i--][j] = c++;
            }
            i++, j++;
        }
        return m;
    }
};