class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) {
            adj[i - 1].emplace_back(i);
        }
        vector<int> ans;
        for(auto& query : queries) {
            adj[query[0]].push_back(query[1]);
            queue<int> bfsQueue;
            vector<int> dis(n, 1e9);
            bfsQueue.push(0);
            dis[0] = 0;
            while(!bfsQueue.empty()) {
                int u = bfsQueue.front();
                bfsQueue.pop();
                if(u == n - 1) {
                    ans.emplace_back(dis[u]);
                    break;
                }
                for(int v : adj[u]) {
                    if(dis[v] > dis[u] + 1) {
                        dis[v] = dis[u] + 1;
                        bfsQueue.push(v);
                    }
                }
            }
        }
        return ans;
    }
};