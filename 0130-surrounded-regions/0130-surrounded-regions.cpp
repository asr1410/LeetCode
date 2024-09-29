class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O' and (i == 0 or j == 0 or i == m - 1 or j == n - 1)) {
                    q.push(make_pair(i, j));
                    board[i][j] = 'A';
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
                if(min(ur, uc) >= 0 and ur < m and uc < n and board[ur][uc] == 'O') {
                    board[ur][uc] = 'A';
                    q.push(make_pair(ur, uc));
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};