class neighborSum {
public:
    vector<vector<int>> mat;
    int n = 0;
    
    bool check(int r, int c) {
        return r >= 0 && c >= 0 && r < n && c < n;
    }
    
    unordered_map<int, pair<int, int>> umap;
    vector<vector<int>> adj{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    vector<vector<int>> dig{{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    
    neighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        mat.resize(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mat[i][j] = grid[i][j];
                umap[grid[i][j]] = {i, j};
            }
        }
    }
    
    int adjacentSum(int value) {
        int sum = 0;
        auto [row, col] = umap[value];
        for(const auto& dir : adj) {
            int urow = row + dir[0];
            int ucol = col + dir[1];
            if(check(urow, ucol)) {
                sum += mat[urow][ucol];
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        int sum = 0;
        auto [row, col] = umap[value];
        for(const auto& dir : dig) {
            int urow = row + dir[0];
            int ucol = col + dir[1];
            if(check(urow, ucol)) {
                sum += mat[urow][ucol];
            }
        }
        return sum;
    }
};