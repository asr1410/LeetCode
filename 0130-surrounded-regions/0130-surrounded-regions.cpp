class Solution {
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int& rows, int& cols, int row, int col) {
        if(row >= 0 and col >= 0 and row < rows and col < cols and board[row][col] == 'O' and vis[row][col] == 0) {
            vis[row][col] = 1;
            dfs(board, vis, rows, cols, row - 1, col);
            dfs(board, vis, rows, cols, row, col - 1);
            dfs(board, vis, rows, cols, row, col + 1);
            dfs(board, vis, rows, cols, row + 1, col);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> vis(rows, vector<int> (cols, 0));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 'O' && (i == 0 || i == rows - 1 || (j == 0 || j == cols - 1))) {
                    dfs(board, vis, rows, cols, i, j);
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