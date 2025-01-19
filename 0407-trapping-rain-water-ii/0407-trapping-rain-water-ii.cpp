class Solution {
public:
    int m, n;

    void dfs(int i, int j, vector<vector<int>>& check) {
        if (i < 0 || j < 0 || i == m || j == n || check[i][j] != 0) {
            return;
        }
        check[i][j] = -1;
        dfs(i, j + 1, check);
        dfs(i, j - 1, check);
        dfs(i + 1, j, check);
        dfs(i - 1, j, check);
    }

    int trapRainWater(vector<vector<int>>& g) {
        int ans = 0;
        m = g.size();
        n = g[0].size();
        set<int> heights; // Set to store unique heights

        // Collect all unique heights
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights.insert(g[i][j]);
            }
        }

        vector<vector<int>> check(m, vector<int>(n, 0));
        int last_height = *heights.begin(); // Start with the minimum height in the set

        // Iterate through all unique heights
        for (int current_height : heights) {
            // Update check matrix for the current height
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    check[i][j] = g[i][j] >= current_height;
                }
            }

            // Flood-fill from the boundaries to mark unreachable cells
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && check[i][j] == 0) {
                        dfs(i, j, check);
                    }
                }
            }

            // Count trapped water cells at this height level
            int trapped_cells = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (check[i][j] == 0) {
                        trapped_cells++;
                    }
                    check[i][j] = 0; // Reset check matrix
                }
            }

            // Calculate water trapped for the height difference
            ans += trapped_cells * (current_height - last_height);
            last_height = current_height; // Update last height
        }

        return ans;
    }
};
