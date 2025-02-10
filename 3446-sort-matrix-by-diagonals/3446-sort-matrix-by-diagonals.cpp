class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int i = m - 1; i >= 0; i--) {
            vector<int> temp;

            int ti = i, tj = 0, idx = 0;
            while(ti < m and tj < n) {
                temp.push_back(grid[ti][tj]);
                ti++, tj++;
            }
            sort(temp.begin(), temp.end(), greater<int>());
            ti = i, tj = 0;
            while(ti < m and tj < n) {
                grid[ti][tj] = temp[idx];
                ti++, tj++, idx++;
            }
        }

        for(int j = 1; j < m; j++) {
            vector<int> temp;

            int ti = 0, tj = j, idx = 0;
            while(ti < m and tj < n) {
                temp.push_back(grid[ti][tj]);
                ti++, tj++;
            }

            sort(temp.begin(), temp.end());

            ti = 0, tj = j, idx = 0;
            while(ti < m and tj < n) {
                grid[ti][tj] = temp[idx];
                ti++, tj++, idx++;
            }
        }
        return grid;
    }
};
