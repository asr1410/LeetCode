class Solution {
    void dfs(const vector<vector<int>>& graph, vector<int>& vis, const int &n, int node) {
        vis[node] = 1;
        for(int i = 0; i < n; i++) {
            if(graph[node][i] == 1 and vis[i] == 0) {
                dfs(graph, vis, n, i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                dfs(graph, vis, n, i);
                ans++;
            }
        }
        return ans;
    }
};