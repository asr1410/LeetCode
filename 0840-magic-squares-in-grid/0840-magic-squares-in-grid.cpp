class Solution {
public:
    bool check(int row, int col, vector<vector<int>>& grid) {
        vector<int> count(10);
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if(grid[i][j] >= 1 and grid[i][j] <= 9) {
                    count[grid[i][j]] = 1;
                }
            }
        }
        if(accumulate(count.begin() + 1, count.end(), 0) != 9) {
            return false;
        }
        unordered_set<int> uset;
        int sum = 0;
        for (int i = row; i < row + 3; i++) {
            sum = 0;
            for (int j = col; j < col + 3; j++) {
                sum += grid[i][j];
            }
            uset.emplace(sum);
            if (uset.size() > 1) {
                return false;
            }
        }
        
        for (int i = col; i < col + 3; i++) {
            sum = 0;
            for (int j = row; j < row + 3; j++) {
                sum += grid[j][i];
            }
            uset.emplace(sum);
            if (uset.size() > 1) {
                return false;
            }
        }
        
        sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += grid[row + i][col + i];
        }
        uset.emplace(sum);
        if (uset.size() > 1) {
            return false;
        }
        sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += grid[row + 2 - i][col + i];
        }
        uset.emplace(sum);
        if (uset.size() > 1) {
            return false;
        }
        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size() - 2;
        int cols = grid[0].size() - 2;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (check(i, j, grid)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};