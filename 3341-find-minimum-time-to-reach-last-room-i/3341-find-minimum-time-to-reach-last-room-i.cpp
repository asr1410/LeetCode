class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        int m = mt.size(), n = mt[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minpq;
        minpq.push(make_pair(0, make_pair(0, 0)));
        vector<vector<int>> dis(m, vector<int> (n, INT_MAX));
        dis[0][0] = mt[0][0];
        int dir[5] = {-1, 0, 1, 0, -1};
        
        while(!minpq.empty()) {
            auto top = minpq.top();
            minpq.pop();
            int x = top.second.first;
            int y = top.second.second;
            int t = top.first;
            
            if(x == m - 1 && y == n - 1) {
                return t;
            }
            
            for(int i = 0; i < 4; i++) {
                int ux = x + dir[i];
                int uy = y + dir[i + 1];
                if(ux >= 0 && uy >= 0 && ux < m && uy < n) {
                    int mcost = max(t + 1, mt[ux][uy] + 1);
                    if(dis[ux][uy] > mcost) {
                        dis[ux][uy] = mcost;
                        minpq.push(make_pair(mcost, make_pair(ux, uy)));
                    }
                }
            }
        }
        return 0;
    }
};