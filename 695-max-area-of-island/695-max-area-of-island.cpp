class Solution {
public:
    void recursive(vector<vector<int>> &grid, int &area, int i, int j)
{
    if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j] != 1)
    {
        return;
    }
    grid[i][j] = 0;
    area += 1;
    recursive(grid, area, i, j+1);
    recursive(grid, area, i + 1, j);
    recursive(grid, area, i, j - 1);
    recursive(grid, area, i - 1, j);
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = INT_MIN;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            int area = 0;
            if (grid[i][j] == 1)
            {
                recursive(grid, area, i, j);
            }
            maxarea = max(area, maxarea);
        }
    }
    return maxarea;
    }
};