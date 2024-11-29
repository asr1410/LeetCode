class Solution {
public:
    int dir[5] = {0, 1, 0, -1, 0};
    int minimumTime(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        if (min(g[0][1], g[1][0]) > 1)
            return -1;
        vector<vector<int>> vis(m, vector<int>(n, INT_MAX));
        priority_queue<array<int, 3>> pq;
        pq.push({0, 0, 0});
        while(!pq.empty()) {
            auto [neg_sec, i, j] = pq.top(); pq.pop();
            if (i == m - 1 && j == n - 1)
                break;
            for (int d = 0; d < 4; ++d) {
                int x = i + dir[d], y = j + dir[d + 1];
                if (min(x, y) >= 0 && x < m && y < n) {
                    int sec = -neg_sec + 1;
                    if (sec < g[x][y])
                        sec = g[x][y] + (g[x][y] - sec) % 2;
                    if (sec < vis[x][y]) {
                        vis[x][y] = sec;
                        pq.push({-sec, x, y});
                    }
                }
            }
        }
        return vis.back().back();
    }
};
