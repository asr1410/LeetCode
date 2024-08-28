class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if(i < 0 or j < 0 or i == m or j == n ) {
        	return 1;
        }
        if(grid2[i][j] == 1 and grid1[i][j] == 0) {
        	return 0;
        }
        if(grid2[i][j] == 0 and grid1[i][j] == 1) {
        	return 1;
        }
        if(grid2[i][j] == 0 and grid1[i][j] == 0) {
        	return 1;
        }
        grid1[i][j] = grid2[i][j] = 0;
        return min({dfs(i + 1, j, m, n, grid1, grid2), dfs(i - 1, j, m, n, grid1, grid2), dfs(i, j + 1, m, n, grid1, grid2), dfs(i, j - 1, m, n, grid1, grid2)});
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size(), ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1 and grid1[i][j] == 1) {
                    ans += dfs(i, j, m, n, grid1, grid2);
                }
            }
        }
        return ans;
    }
};
