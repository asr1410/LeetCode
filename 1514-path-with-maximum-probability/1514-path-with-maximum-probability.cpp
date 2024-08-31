#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});

        while (!pq.empty()) {
            double curProb = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (u == end) {
                return curProb;
            }

            if (curProb < maxProb[u]) {
                continue;
            }

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                double edgeProb = neighbor.second;
                double newProb = curProb * edgeProb;
                if (newProb > maxProb[v]) {
                    maxProb[v] = newProb;
                    pq.push({newProb, v});
                }
            }
        }

        return 0.0;
    }
};
