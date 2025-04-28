#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> bit;
    int n;
public:
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 2, 0); // safer size
    }
    void update(int i, int val) {
        i++; // make 1-based
        while (i <= n + 1) {
            bit[i] += val;
            i += (i & -i);
        }
    }
    int query(int i) {
        i++; // make 1-based
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> breaks(n-1, 0);
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i-1] > maxDiff) {
                breaks[i-1] = 1;
            }
        }

        FenwickTree fen(n-1);
        for (int i = 0; i < n-1; i++) {
            if (breaks[i]) {
                fen.update(i, 1);
            }
        }

        vector<bool> ans;
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(true);
            } else {
                int l = min(u, v), r = max(u, v) - 1; // notice -1 because breaks are between nodes
                ans.push_back(fen.rangeQuery(l, r) == 0);
            }
        }
        return ans;
    }
};
