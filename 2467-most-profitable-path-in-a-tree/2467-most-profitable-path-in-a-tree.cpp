class Solution {
public:
    unordered_map<int, int> bobPath;
    int maxScore = INT_MIN;
    
    void dfs(int node, int parent, int level, int currentScore, vector<vector<int>>& adj, vector<int>& amount) {
        int currentAmount = amount[node];
        
        if (bobPath.count(node)) {
            if (bobPath[node] == level) {
                currentAmount = amount[node] / 2;
            } else if (bobPath[node] < level) {
                currentAmount = 0;
            }
        }
        
        currentScore += currentAmount;
        
        bool isLeaf = true;
        for (int next : adj[node]) {
            if (next != parent) {
                isLeaf = false;
                dfs(next, node, level + 1, currentScore, adj, amount);
            }
        }
        
        if (isLeaf) {
            maxScore = max(maxScore, currentScore);
        }
    }
    
    bool findBobPath(int node, int parent, int level, vector<vector<int>>& adj) {
        if (node == 0) {
            bobPath[node] = level;
            return true;
        }
        
        for (int next : adj[node]) {
            if (next != parent) {
                if (findBobPath(next, node, level + 1, adj)) {
                    bobPath[node] = level;
                    return true;
                }
            }
        }
        return false;
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        findBobPath(bob, -1, 0, adj);
        dfs(0, -1, 0, 0, adj, amount);
        
        return maxScore;
    }
};