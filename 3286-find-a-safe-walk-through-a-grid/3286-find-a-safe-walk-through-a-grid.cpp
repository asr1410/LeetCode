class Solution {
public:
bool findSafeWalk(vector<vector<int>>& g, int health) {
    int m = g.size(), n = g[0].size(), cnt[51][51] = {};
    priority_queue<array<int, 3>> pq;
    pq.push({health - g[0][0], 0, 0});
    while (!pq.empty()) {
        auto [h, i, j] = pq.top(); pq.pop();
        if (i == m - 1 && j == n - 1)
            return true;
        for (auto [dx, dy] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
            int x = i + dx, y = j + dy;
            if (min(x, y) >= 0 && x < m && y < n && cnt[x][y] < h - g[x][y]) {
                cnt[x][y] = h - g[x][y];
                pq.push({h - g[x][y], x, y});
            }
        }
    }
    return false;
}
};
