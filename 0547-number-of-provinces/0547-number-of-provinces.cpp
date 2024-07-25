class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> umap[n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    umap[i].push_back(j);
                }
            }
        }
        
        int ans = 0;
        vector<int> vis(n);
        
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                ans++;
                
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for(auto neighbor : umap[node]) {
                        if(vis[neighbor] == 0) {
                            q.push(neighbor);
                            vis[neighbor] = 1;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};