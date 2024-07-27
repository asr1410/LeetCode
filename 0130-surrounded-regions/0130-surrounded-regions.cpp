class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(rows, vector<int> (cols, 0));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 'O' && (i == 0 || i == rows - 1 || (j == 0 || j == cols - 1))) {
                    q.emplace(i, j);
                    vis[i][j] = 1;
                }
            }
        }
        int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        while(q.empty() == false) {
            int size = q.size();
            while(size--) {
                auto [row, col] = q.front();
                q.pop();
                for(auto &d:dir) {
                    int nrow = d[0] + row;
                    int ncol = d[1] + col;
                    if(nrow >= 0 and ncol >= 0 and nrow < rows and ncol < cols and board[nrow][ncol] == 'O' and vis[nrow][ncol] == 0) {
                        vis[nrow][ncol] = 1;
                        q.emplace(nrow, ncol);
                    }
                }
            }
        }
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};