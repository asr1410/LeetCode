class DS {
public:
    vector<int> parent, size;
    DS (int n) {
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int uparent(int n) {
        if(parent[n] == n) {
            return n;
        }
        return parent[n] = uparent(parent[n]);
    }
    
    void ujoin(int a, int b) {
        int upa = uparent(a);
        int upb = uparent(b);
        if(upa != upb) {
            if(size[upa] < size[upb]) {
                parent[upa] = upb;
                size[upb] += size[upa];
            } else {
                parent[upb] = upa;
                size[upa] += size[upb];
            }
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int m = 0, n = 0;
        for (int i = 0; i < stones.size(); i++) {
            m = max(m, stones[i][0] + 1);
            n = max(n, stones[i][1] + 1);
        }
        unordered_set<int> uset;
        DS ds(m + n);
        for(auto stone : stones) {
            int row = stone[0];
            int col = m + stone[1];
            ds.ujoin(row, col);
            uset.insert(row);
            uset.insert(col);
        }
        
        int count = 0;
        for(auto it : uset) {
            if(ds.uparent(it) == it) {
                count++;
            }
        }
        return stones.size() - count;
    }
};
