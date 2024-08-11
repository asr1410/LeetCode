#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        int dir[2][2] = {{1, 0}, {0, 1}};
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            for (int d = 0; d < 2; ++d) {
                int ni = i + dir[d][0];
                int nj = j + dir[d][1];
                
                if (ni < m && nj < n) {
                    if (dp[ni][nj] == 0) {
                        q.push({ni, nj});
                    }
                    dp[ni][nj] += dp[i][j];
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};