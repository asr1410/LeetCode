#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        vector<int> directions = {1, 0, 0, 1};
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            for (int d = 0; d < 2; ++d) {
                int ni = i + directions[2 * d];
                int nj = j + directions[2 * d + 1];
                
                if (ni < m && nj < n) {
                    dp[ni][nj] += dp[i][j];
                    
                    if (dp[ni][nj] == dp[i][j]) {
                        q.push({ni, nj});
                    }
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
