class Solution {
public:
    int parent[101];
    int uparent(int u) {
        if(parent[u] == u) {
            return u;
        }
        return parent[u] = uparent(parent[u]);
    }

    void ujoin(int a, int b) {
        int upa = uparent(a);
        parent[b] = upa;
    }

    int findChampion(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < 101; i++)
            parent[i] = i;
        for(auto edge : edges) {
            ujoin(edge[0], edge[1]);
        }
        int ans = -1;
        for(int i = 0, t = 0; i < n; i++) {
            if(parent[i] == i) {
                ans = i;
                t++;
                if(t == 2) {
                    return -1;
                }
            }
        }
        return ans;
    }
};
