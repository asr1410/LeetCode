class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        
        for (int i = 1; i < n; i++) {
            mat[i - 1][i] = 1;
        }

        for (auto q : queries) {
            mat[q[0]][q[1]] = 1;
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.emplace(0, 0);
            dist[0] = 0;

            while (!pq.empty()) {
                int u = pq.top().second;
                int d = pq.top().first;
                pq.pop();

                if (u == n - 1) {
                    ans.push_back(d);
                    break;
                }

                for (int i = 0; i < n; i++) {
                    if (mat[u][i] == 1 && d + 1 < dist[i]) {
                        dist[i] = d + 1;
                        pq.emplace(dist[i], i);
                    }
                }
            }
        }

        return ans;
    }
};
