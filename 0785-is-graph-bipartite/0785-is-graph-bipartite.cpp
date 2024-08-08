class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int node, int parent, int col) {
        vis[node] = col;
        for(auto& it : graph[node]) {
            if(vis[it] == -1) {
                if(dfs(graph, vis, it, node, col ^ 1) == false) {
                    return false;
                }
            } else if(it != parent and vis[it] == vis[node]) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        
        for(int i = 0; i < n; i++) {
            if(vis[i] == -1) {
                if(dfs(graph, vis, i, -1, 0) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};

