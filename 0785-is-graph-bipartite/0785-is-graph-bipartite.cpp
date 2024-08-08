class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int node, int col) {
        vis[node] = col;
        for (auto& it : graph[node]) {
            if (vis[it] == -1) {
                if (!dfs(graph, vis, it, col ^ 1)) {
                    return false;
                }
            } else if (vis[it] == vis[node]) {
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) { // Start DFS for each component
                if (!dfs(graph, vis, i, 0)) {
                    return false;
                }
            }
        }
        return true;
    }
};