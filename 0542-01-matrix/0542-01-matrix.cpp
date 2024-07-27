class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(rows, vector<int>(cols, -1));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 0) {
                    q.emplace(i, j);
                    dist[i][j] = 0;
                }
            }
        }
        
        int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        int count = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [row, col] = q.front();
                q.pop();
                for (auto& d : dir) {
                    int nr = row + d[0];
                    int nc = col + d[1];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && dist[nr][nc] == -1) {
                        dist[nr][nc] = count;
                        q.emplace(nr, nc);
                    }
                }
            }
            count++;
        }
        
        return dist;
    }
};