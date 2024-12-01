class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> pq;
        pq.emplace(array<int, 4>{0, 0, 0, 1});
        int m = mt.size(), n = mt[0].size();
        int dir[5] = {-1, 0, 1, 0, -1};
        vector<vector<int>> vis(m, vector<int>(n, 0));

        while (!pq.empty()) {
            auto [move, row, col, step] = pq.top();
            pq.pop();
            if (row == m - 1 && col == n - 1) {
                return move;
            }
            if (vis[row][col] == 1) continue;
            vis[row][col] = 1;

            for (int i = 1; i < 5; i++) {
                int nrow = dir[i - 1] + row, ncol = dir[i] + col;
                if (nrow < 0 || ncol < 0 || nrow >= m || ncol >= n || vis[nrow][ncol] == 1) continue;
                pq.emplace(array<int, 4>{max(move, mt[nrow][ncol]) + (step == 1 ? 1 : 2), nrow, ncol, step == 1 ? 2 : 1});
            }
        }
        return -1;
    }
};
