class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) {
            adj[i - 1].emplace_back(i);
        }
        vector<int> ans;
        for(auto& q : queries) {
            adj[q[0]].push_back(q[1]);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int> dis(n, 1e9);
            pq.emplace(0, 0);
            dis[0] = 0;
            while(!pq.empty()) {
                int u = pq.top().second;
                int d = pq.top().first;
                pq.pop();
                if(u == n - 1) {
                    ans.emplace_back(d);
                    break;
                }
                for(int v : adj[u]) {
                    if(dis[v] > d + 1) {
                        dis[v] = d + 1;
                        pq.emplace(d + 1, v);
                    }
                }
            }
        }
        return ans;
    }
};