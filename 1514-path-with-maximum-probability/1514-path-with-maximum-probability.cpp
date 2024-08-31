class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sp, int sn, int en) {
        vector<double> mp(n, 0);
        mp[sn] = 1;
        
        for(int i = 1; i < n; i++) {
            bool updated = false;
            for(int j = 0; j < edges.size(); j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                double prob = sp[j];
                if(mp[u] * prob > mp[v]) {
                    mp[v] = mp[u] * prob;
                    updated = true;
                }
                if(mp[v] * prob > mp[u]) {
                    mp[u] = mp[v] * prob;
                    updated = true;
                }
            }
            if(updated == false) {
                break;
            }
        }
        return mp[en];
    }
};