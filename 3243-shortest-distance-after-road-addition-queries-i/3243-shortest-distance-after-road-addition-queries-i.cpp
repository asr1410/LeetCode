class Solution {
public:
    #define pi pair<int, int>
    vector<list<pi>> graph;
    int dijkstra(int n){
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, 0});

        while(! pq.empty()){
            auto ele = pq.top();
            int cd = ele.first, node = ele.second;
            pq.pop();
            if(node == n - 1) return dist[n-1];
            if(cd > dist[node]) continue;

            for(auto ele : graph[node]){
                int nbr = ele.first, wt = ele.second;
                if(cd + wt < dist[nbr]){
                    dist[nbr] = cd + wt;
                    pq.push({cd + wt, nbr});
                }
            }
        }
        return dist[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        graph.clear();
        graph.resize(n);
        vector<int> res;
        for(int i = 0; i < n - 1; ++i){
            graph[i].push_back({i + 1, 1});
        }
        for(auto ele : queries){
            graph[ele[0]].push_back({ele[1], 1});
            int d = dijkstra(n);
            res.push_back(d);
        }
        return res;
    }
};