class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<pair<int, pair<int, int>>> pq;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        pq.push(make_pair(health - grid[0][0], make_pair(0, 0)));
        vector<vector<int>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        while (!pq.empty()) {
            auto top = pq.top();
            int i = top.second.first;
            int j = top.second.second;
            int currentHealth = top.first;
            pq.pop();
            if (i == m - 1 && j == n - 1 && currentHealth > 0) {
                return true;
            }
            for (auto d : dir) {
                int ni = i + d[0];
                int nj = j + d[1];
                if (ni >= 0 && nj >= 0 && ni < m && nj < n && vis[ni][nj] == 0 && currentHealth > 0) {
                    vis[ni][nj] = 1;
                    pq.push(make_pair(currentHealth - grid[ni][nj], make_pair(ni, nj)));
                }
            }
        }
        return false;
    }
};
