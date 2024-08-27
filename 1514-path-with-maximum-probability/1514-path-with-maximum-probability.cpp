#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    double maxProbability(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int start, int end) {
        std::vector<std::vector<std::pair<int, double>>> al(n);
        for (size_t i = 0; i < edges.size(); ++i) {
            al[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            al[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        
        std::vector<double> probs(n, 0.0);
        probs[start] = 1.0;

        std::queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int from = q.front();
            q.pop();
            
            for (const auto& [to, prob] : al[from]) {
                if (probs[to] < probs[from] * prob) {
                    probs[to] = probs[from] * prob;
                    q.push(to);
                }
            }
        }
        
        return probs[end];
    }
};
