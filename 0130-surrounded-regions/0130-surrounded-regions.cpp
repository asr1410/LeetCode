class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int rows = board.size(), cols = board[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if((i == 0 or j == 0 or i == rows - 1 or j == cols - 1) and board[i][j] == 'O') {
                    q.emplace(i, j);
                    board[i][j] = 'a';
                }
            }
        }
        int dirr[4] = {-1, 0, 0, 1};
        int dirc[4] = {0, -1, 1, 0};
        
        while(q.empty() == false) {
            pair<int, int> front = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int urow = front.first + dirr[i];
                int ucol = front.second + dirc[i];
                if(urow >= 0 and ucol >= 0 and urow < rows and ucol < cols and board[urow][ucol] == 'O') {
                    board[urow][ucol] = 'a';
                    q.emplace(urow, ucol);
                }
            }
        }
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 'a') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};