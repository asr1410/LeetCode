class Solution {
public:
    unordered_map<int, int> b;
    int maxScore = INT_MIN;
    
    void dfs(int u, int p, int l, int cs, vector<vector<int>>& adj, vector<int>& a) {
        int t = a[u];
        
        if (b.count(u)) {
            if (b[u] == l) {
                t = a[u] / 2;
            } else if (b[u] < l) {
                t = 0;
            }
        }
        
        cs += t;
        
        bool isLeaf = true;
        for (int next : adj[u]) {
            if (next != p) {
                isLeaf = false;
                dfs(next, u, l + 1, cs, adj, a);
            }
        }
        
        if (isLeaf) {
            maxScore = max(maxScore, cs);
        }
    }
    
    bool findBobPath(int u, int p, int l, vector<vector<int>>& adj) {
        if (u == 0) {
            b[u] = l;
            return true;
        }
        
        for (int next : adj[u]) {
            if (next != p) {
                if (findBobPath(next, u, l + 1, adj)) {
                    b[u] = l;
                    return true;
                } else {
                    b.erase(u);
                }
            }
        }
        return false;
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& a) {
        int n = a.size();
        
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        findBobPath(bob, -1, 0, adj);
        dfs(0, -1, 0, 0, adj, a);
        
        return maxScore;
    }
};