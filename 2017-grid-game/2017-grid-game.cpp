class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> pre(n, 0), pos(n, 0);
        pre[0] = grid[0][0], pos[n - 1] = grid[1][n - 1];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + grid[0][i];
            pos[n - i - 1] = pos[n - i] + grid[1][n - i - 1];
        }
        long long tsum1 = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long tsum2 = accumulate(grid[1].begin(), grid[1].end(), 0LL);
        long long ans = 1e15;
        for(int i = 0; i < n; i++) {
            ans = min(ans, max(tsum1 - pre[i], tsum2 - pos[i]));
        }
        // [20,03,20,17,02,12,15,17,04,15]
        // [20,10,13,14,15,05,02,03,14,03]
        return ans;
    }
};