class Solution {
public:
    void ts(int node, vector<int> adj[], vector<int>& vis, vector<int>& temp) {
        vis[node] = 1;
        for(auto& it : adj[node]) {
            if(vis[it] == 0) {
                ts(it, adj, vis, temp);
            }
        }
        temp.emplace_back(node);
    }
    
    void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& mark, int& cycle) {
        vis[node] = 1;
        mark[node] = 1;
        for(auto& it : adj[node]) {
            if(vis[it] == 0) {
                dfs(it, adj, vis, mark, cycle);
            } else if(mark[it] == 1) {
                cycle = 1;
            }
        }
        mark[node] = 0;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        int n = k + 1;
        vector<int> radj[n];
        vector<int> cadj[n];
        vector<int> rvis(n, 0);
        vector<int> cvis(n, 0);
        vector<int> rmark(n, 0);
        vector<int> cmark(n, 0);
        
        for(auto& r : rc) {
            radj[r[0]].emplace_back(r[1]);
        }
        
        for(auto& c : cc) {
            cadj[c[0]].emplace_back(c[1]);
        }
        
        int rcycle = 0, ccycle = 0;
        for(int i = 1; i < n; i++) {
            if(rvis[i] == 0) {
                dfs(i, radj, rvis, rmark, rcycle);
            }
        }
        
        for(int i = 1; i < n; i++) {
            if(cvis[i] == 0) {
                dfs(i, cadj, cvis, cmark, ccycle);
            }
        }
        
        if(rcycle or ccycle) {
            return {};
        }
        
        vector<vector<int>> ans(k, vector<int>(k, 0));
        
        rvis.assign(n, 0);
        cvis.assign(n, 0);
        
        vector<int> rts;
        vector<int> cts;
        
        for(int i = 1; i < n; i++) {
            if(rvis[i] == 0) {
                ts(i, radj, rvis, rts);
            }
        }
        
        for(int i = 1; i < n; i++) {
            if(cvis[i] == 0) {
                ts(i, cadj, cvis, cts);
            }
        }
        
        reverse(rts.begin(), rts.end());
        reverse(cts.begin(), cts.end());
        
        // Map each number to its position in the topological order
        unordered_map<int, int> rowIndex;
        unordered_map<int, int> colIndex;
        
        for (int i = 0; i < k; ++i) {
            rowIndex[rts[i]] = i;
            colIndex[cts[i]] = i;
        }
        
        for (int i = 1; i <= k; ++i) {
            int row = rowIndex[i];
            int col = colIndex[i];
            ans[row][col] = i;
        }
        
        return ans;
    }
};