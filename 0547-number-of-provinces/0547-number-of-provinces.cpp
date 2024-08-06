class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& mat) {
        vis[node] = 1;
        for(int i = 0; i < mat.size(); i++) {
            if(vis[i] == 0 and mat[node][i] == 1 and node != i) {
                dfs(i, vis, mat);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                dfs(i, vis, isConnected);
                ans++;
            }
        }
        return ans;
    }
};