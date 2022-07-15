class Solution
{
public:
    void helper(int row, int col, vector<vector<int>> &grid, int &temp)
    {
        if (row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0 || grid[row][col] != 1)
        {
            return;
        }
        grid[row][col] = 0;
        temp++;
        helper(row, col - 1, grid, temp);
        helper(row, col + 1, grid, temp);
        helper(row - 1, col, grid, temp);
        helper(row + 1, col, grid, temp);
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int maxarea = INT_MIN;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                int temp = 0;
                helper(i, j, grid, temp);
                maxarea = max(maxarea, temp);
            }
        }
        return maxarea;
    }
};