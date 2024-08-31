class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sp, int sn, int en) {
        vector<pair<int, double>> adj[n];
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(make_pair(edges[i][1], sp[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0], sp[i]));
        }
        
        vector<double> vis(n, 0);
        priority_queue<pair<double, int>> pq;
        vis[sn] = 1;
        pq.push(make_pair(1, sn));
        while(pq.empty() == false) {
            double prob = pq.top().first;
            int u = pq.top().second;
            if(u == en) {
                return prob;
            }
            pq.pop();
            for(auto v : adj[u]) {
                if(v.second * prob > vis[v.first]) {
                    vis[v.first] = v.second * prob;
                    pq.push(make_pair(vis[v.first], v.first));
                }
            }
        }
        
        return 0;
    }
};