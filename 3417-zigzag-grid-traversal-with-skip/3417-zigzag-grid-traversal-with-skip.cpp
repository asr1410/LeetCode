class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        bool flag = true;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            if(i & 1) {
                for(int j = n - 1; j >= 0; j--) {
                    if(flag) {
                        ans.push_back(grid[i][j]);
                        flag = false;
                    } else {
                        flag = true;
                    }
                }
            } else {
                for(int j = 0; j < n; j++) {
                    if(flag) {
                        ans.push_back(grid[i][j]);
                        flag = false;
                    } else {
                        flag = true;
                    }
                }
            }
        }
        return ans;
    }
};