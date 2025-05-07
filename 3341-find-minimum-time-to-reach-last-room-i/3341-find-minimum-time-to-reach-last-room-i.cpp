class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        vector<vector<int>> vis(m, vector<int>(n, INT_MAX));
        vis[0][0] = 0;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        pq.push({0, 0, 0}); // time, row, col

        int dir[5] = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            auto [time, row, col] = pq.top();
            pq.pop();

            if (time > vis[row][col]) continue;
            if (row == m - 1 && col == n - 1) return time;

            for (int i = 0; i < 4; i++) {
                int nrow = row + dir[i], ncol = col + dir[i + 1];
                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n) {
                    int ntime = max(time, moveTime[nrow][ncol]) + 1;
                    if (ntime < vis[nrow][ncol]) {
                        vis[nrow][ncol] = ntime;
                        pq.push({ntime, nrow, ncol});
                    }
                }
            }
        }
        return -1;
    }
};
