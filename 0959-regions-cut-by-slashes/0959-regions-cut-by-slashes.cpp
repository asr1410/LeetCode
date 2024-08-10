#include <vector>
#include <numeric>
#include <string>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;
    int count;
    
    DisjointSet(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n + 1, 1);
        count = 1;
    }
    
    int uparent(int n) {
        if (n == parent[n]) {
            return n;
        }
        return parent[n] = uparent(parent[n]);
    }
    
    void ujoin(int a, int b) {
        int upa = uparent(a);
        int upb = uparent(b);
        
        if (upa != upb) {
            if (size[upa] > size[upb]) {
                parent[upb] = upa;
                size[upa] += size[upb];
            } else {
                parent[upa] = upb;
                size[upb] += size[upa];
            }
        } else {
            count++;
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size(), d = n + 1;
        DisjointSet ds(d * d);
        
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                if (i == 0 || j == 0 || i == n || j == n) {
                    int cell = i * d + j;
                    if(cell != 0)
                        ds.ujoin(0, cell);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '/') {
                    int cell1 = i * d + j + 1;
                    int cell2 = (i + 1) * d + j;
                    ds.ujoin(cell1, cell2);
                } else if (grid[i][j] == '\\') {
                    int cell1 = i * d + j;
                    int cell2 = (i + 1) * d + j + 1;
                    ds.ujoin(cell1, cell2);
                }
            }
        }
        
        return ds.count;
    }
};