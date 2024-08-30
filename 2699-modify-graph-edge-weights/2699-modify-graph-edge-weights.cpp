using ll = long long;
#define pb push_back
#define ve vector
#define FOR(i, a, b) for (int i = a; i < b; ++i)
using namespace std;

const int N = 105;
const int M = 1e5 + 10;
const ll INF = 1000000000000000ll;

vector<pair<int, int>> g[N];
ll d[N];

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int s, int de, int target) {
        FOR(i, 0, n) {
            g[i].clear();
            d[i] = INF;
        }
        
        queue<int> q;
        FOR(i, 0, edges.size()) {
            auto& e = edges[i];
            if(e[2] == -1) {
                continue;
            }
            int u = e[0], v = e[1], w = e[2];
            g[u].pb({v, w});
            g[v].pb({u, w});
        }
        
        d[s] = 0;
        q.push(s);
        while(q.size()) {
            int u = q.front();
            q.pop();
            for(auto& p : g[u]) {
                int nxt = p.first, w = p.second;
                if(d[nxt] > d[u] + w) {
                    d[nxt] = d[u] + w;
                    q.push(nxt);
                }
            }
        }
        
        if(d[de] < target) {
            return {};
        }
        
        if(d[de] == target) {
            for(auto& e : edges) {
                if(e[2] == -1) e[2] = 1e9;
            }
            return edges;
        }
        
        FOR(i, 0, edges.size()) {
            auto& e = edges[i];
            int u = e[0], v = e[1], w = e[2];
            if(w == -1) {
                e[2] = 1;
                g[u].pb({v, 1});
                g[v].pb({u, 1});
                //run bfs
                while(q.size()) q.pop();
                FOR(i, 0, n) d[i] = INF;
                d[s] = 0;
                q.push(s);
                while(q.size()) {
                    int u = q.front();
                    q.pop();
                    for(auto& p : g[u]) {
                        int nxt = p.first, w = p.second;
                        if(d[nxt] > d[u] + w) {
                            d[nxt] = d[u] + w;
                            q.push(nxt);
                        }
                    }
                }
                
                if(d[de] <= target) {
                    e[2] += (target - d[de]);
                    FOR(j, i + 1, edges.size()) {
                        if(edges[j][2] == -1) {
                           edges[j][2] = 1e9; 
                        }
                    }
                    return edges;
                }
            }
        }
        return {};
    }
};
