class Solution {
public:
    int dp[1024][101];
    int helper(int n, vector<int>& temp, unordered_map<int, vector<int>>& umap, int mask) {
        if(n < 0) {
            return 0;
        }
        if(dp[mask][n] != -1) {
            return dp[mask][n];
        }
        int ans = 0;
        for(int shift : umap[temp[n]]) {
            if(((1 << shift) & mask) == 0) {
                ans = max(ans, temp[n] + helper(n - 1, temp, umap, mask | (1 << shift)));
            }
        }
        ans = max(ans, helper(n - 1, temp, umap, mask));
        return dp[mask][n] = ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        unordered_set<int> temp;
        int rows = grid.size(), cols = grid[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                temp.insert(grid[i][j]);
            }
        }
        vector<int> ngrid;
        for(auto it : temp)
            ngrid.push_back(it);
        unordered_map<int, vector<int>> umap;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                umap[grid[i][j]].push_back(i);
            }
        }
        sort(ngrid.begin(), ngrid.end());
        return helper(temp.size() - 1, ngrid, umap, 0);
    }
};