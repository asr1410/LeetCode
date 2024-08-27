class Solution {
public:
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<vector<pair<int, double>>> al(n);
    for (auto i = 0; i < edges.size(); ++i) {
        if (succProb[i] != 0) {
            al[edges[i][0]].push_back({edges[i][1], succProb[i]});
            al[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
    }
    vector<double> probs(n);
    probs[start] = 1;
    vector<int> q{start};
    while(!q.empty()) {
        vector<int> q1;
        for (auto from : q) {
            for (auto [to, prob] : al[from]) {
                if (probs[to] < probs[from] * prob) {
                    probs[to] = probs[from] * prob;
                    q1.push_back(to);
                }
            }
        }
        swap(q, q1);
    }
    return probs[end];
}
};