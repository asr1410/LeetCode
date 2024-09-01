#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int recur(const vector<vector<int>>& values, int idx, int mask_row, unordered_map<long long, int>& dp) {
        int n = values.size();
        if (idx == n)
            return 0;
        
        long long state = ((long long)idx << 10) | mask_row;
        if (dp.find(state) != dp.end())
            return dp[state];
        
        int ans = 0;
        int row = values[idx][1];
        if ((1 << row) & mask_row) {
            ans = recur(values, idx + 1, mask_row, dp);
        } else {
            int j = idx;
            while (j < n && values[idx][0] == values[j][0])
                j++;
            
            int ans1 = values[idx][0] + recur(values, j, mask_row | (1 << row), dp);
            int ans2 = recur(values, idx + 1, mask_row, dp);
            
            ans = max(ans1, ans2);
        }
            
        dp[state] = ans;
        return ans;
    }
    
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> values;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                values.push_back({grid[i][j], i});
            }
        }
        
        sort(values.begin(), values.end(), greater<vector<int>>());
        
        unordered_map<long long, int> dp;
        
        return recur(values, 0, 0, dp);
    }
};
