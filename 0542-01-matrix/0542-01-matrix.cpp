class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push(make_pair(i, j));
                }
            }
        }
        int d[5] = {-1, 0, 1, 0, -1};
        while(q.empty() == false) {
            auto [r, c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int ur = r + d[i];
                int uc = c + d[i + 1];
                if(min(ur, uc) >= 0 and ur < m and uc < n and vis[ur][uc] == 0) {
                    vis[ur][uc] = 1;
                    mat[ur][uc] = mat[r][c] + 1;
                    q.push(make_pair(ur, uc));
                }
            }
        }
        return mat;
    }
};