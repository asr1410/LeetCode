#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sp, int sn, int en) {
        vector<pair<int, double>> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(make_pair(edges[i][1], sp[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0], sp[i]));
        }
        
        vector<double> prob(n, 0.0);
        prob[sn] = 1.0;
        
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, sn});
        
        while (!pq.empty()) {
            double currProb = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (u == en) {
                return currProb;
            }
            
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                double edgeProb = neighbor.second;
                double newProb = currProb * edgeProb;
                
                if (newProb > prob[v]) {
                    prob[v] = newProb;
                    pq.push({newProb, v});
                }
            }
        }
        
        return 0.0;
    }
};