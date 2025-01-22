class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& w) {
        int m = w.size(), n = w[0].size();
        vector<vector<int>> l(m, vector<int>(n, 0));
        vector<vector<int>> v(m, vector<int>(n, 0));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (w[i][j] == 1) {
                    v[i][j] = 1;
                    pq.push({0, i, j});
                }
            }
        }

        int dir[5] = {-1, 0, 1, 0, -1};
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int h = top[0], r = top[1], c = top[2];

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i], nc = c + dir[i + 1];
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && v[nr][nc] == 0) {
                    v[nr][nc] = 1;
                    l[nr][nc] = h + 1;
                    pq.push({h + 1, nr, nc});
                }
            }
        }

        return l;
    }
};
