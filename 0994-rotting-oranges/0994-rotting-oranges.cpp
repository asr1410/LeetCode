class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        int fcount = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                fcount += (grid[i][j] == 1);
            }
        }
        if(fcount == 0) return 0;
        int time = -1;
        int dir[5] = {0, -1, 0, 1, 0};
        while(!q.empty()) {
            time++;
            int t = q.size();
            while(t--) {
                auto top = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int ni = top.first + dir[i];
                    int nj = top.second + dir[i + 1];
                    if(min(ni, nj) >= 0 && ni < m && nj < n && grid[ni][nj] == 1) {
                        grid[ni][nj] = 0;
                        q.push({ni, nj});
                        fcount--;
                    }
                }
            }
        }
        return fcount == 0 ? time : -1;
    }
};
