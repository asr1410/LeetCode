class Solution {
public:
    int countServers(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<int> r(m, 0), c(n, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                c[j] += g[i][j] == 1;
                r[i] += g[i][j] == 1;
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(g[i][j] == 1 and (r[i] > 1 or c[j] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};