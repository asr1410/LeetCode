class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> minpq;
        minpq.push({0, 0, 0, 1});
        int m = mt.size(), n = mt[0].size();
        int dir[5] = {-1, 0, 1, 0, -1};
        vector<vector<int>> mc(m, vector<int>(n, INT_MAX));
        while (!minpq.empty()) {
            auto [cst, row, col, adj] = minpq.top();
            minpq.pop();
            if (cst > mc[row][col]) {
                continue;
            }
            if (row == m - 1 && col == n - 1) {
                return cst;
            }
            for (int i = 0; i < 4; i++) {
                int nrow = row + dir[i], ncol = col + dir[i + 1];
                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n) {
                    int ncst = max(cst, mt[nrow][ncol]);
                    ncst += (adj == 1) ? 1 : 2;
                    if (ncst < mc[nrow][ncol]) {
                        mc[nrow][ncol] = ncst;
                        minpq.push({ncst, nrow, ncol, (adj == 1) ? 2 : 1});
                    }
                }
            }
        }
        return -1;
    }
};
