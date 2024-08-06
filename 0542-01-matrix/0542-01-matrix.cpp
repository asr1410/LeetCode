class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> vis(rows, vector<int> (cols, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(mat[i][j] == 0) {
                    q.emplace(i, j);
                    vis[i][j] = 1;
                }
            }
        }
        int dirr[4] = {-1, 0, 0, 1};
        int dirc[4] = {0, -1, 1, 0};
        int dist = 1;
        while(q.empty() == false) {
            int size = q.size();
            while(size--) {
                auto [row, col] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int urow = row + dirr[i];
                    int ucol = col + dirc[i];
                    if(urow >= 0 and ucol >= 0 and urow < rows and ucol < cols and vis[urow][ucol] == 0) {
                        mat[urow][ucol] = dist;
                        vis[urow][ucol] = 1;
                        q.emplace(urow, ucol);
                    }
                }
            }
            dist++;
        }
        return mat;
    }
};