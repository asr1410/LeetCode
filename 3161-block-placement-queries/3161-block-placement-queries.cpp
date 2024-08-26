#include "bits/stdc++.h"
using namespace std;

class ST {
public:
    vector<int> seg;
    int n;
    
    ST(int n) {
        this->n = n;
        seg.resize(4 * n, 0);
    }
    
    int getRange(int idx, int low, int high, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == low && high == r) {
            return seg[idx];
        }
        int mid = (low + high) >> 1;
        return max(getRange(2 * idx + 1, low, mid, l, min(mid, r)), getRange(2 * idx + 2, mid + 1, high, max(l, mid + 1), r));
    }
    
    void update(int idx, int low, int high, int pos, int val) {
        if (low == high) {
            seg[idx] = val;
        } else {
            int mid = (low + high) >> 1;
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            if (pos <= mid) {
                update(left, low, mid, pos, val);
            } else {
                update(right, mid + 1, high, pos, val);
            }
            seg[idx] = max(seg[left], seg[right]);
        }
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int n = 50001;
        ST st(n);
        set<int> objects;
        vector<bool> ans;
        objects.insert(0);
        objects.insert(50001);
        
        for (auto& q : queries) {
            if (q[0] == 1) {
                auto it = objects.upper_bound(q[1]);
                int r = *it;
                int l = *(prev(it));
                objects.insert(q[1]);
                st.update(0, 0, n - 1, q[1], q[1] - l);
                st.update(0, 0, n - 1, r, r - q[1]);
            } else {
                bool val = st.getRange(0, 0, n - 1, 0, q[1]) >= q[2];
                if (!val) {
                    auto it = objects.lower_bound(q[1]);
                    if (*it != q[1]) {
                        it = prev(it);
                        val = q[1] - *it >= q[2];
                    }
                }
                ans.push_back(val);
            }
        }
        
        return ans;
    }
};