#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    vector<int> t; // Segment tree

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = tl;
        } else {
            int tm = (tl + tr) / 2;
            build(2 * v + 1, tl, tm); // Left child
            build(2 * v + 2, tm + 1, tr); // Right child
            t[v] = min(t[2 * v + 1], t[2 * v + 2]);
        }
    }

    void update(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            t[v] = INT_MAX;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(2 * v + 1, tl, tm, pos); // Left child
            } else {
                update(2 * v + 2, tm + 1, tr, pos); // Right child
            }
            t[v] = min(t[2 * v + 1], t[2 * v + 2]);
        }
    }

    int getFirstAvailable(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        int left = INT_MAX;
        if (l <= tm) {
            left = getFirstAvailable(2 * v + 1, tl, tm, l, r); // Left child
        }
        int right = INT_MAX;
        if (tm + 1 <= r) {
            right = getFirstAvailable(2 * v + 2, tm + 1, tr, l, r); // Right child
        }
        return min(left, right);
    }

public:
    int maxEvents(vector<vector<int>>& events) {
        int n = 100000; // The maximum possible number of days
        t.resize(4 * n);
        build(0, 1, n);

        // Sort events by their end day
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int cnt = 0;
        for (const vector<int>& event : events) {
            int firstAvailable = getFirstAvailable(0, 1, n, event[0], event[1]);
            if (event[0] <= firstAvailable && firstAvailable <= event[1]) {
                cnt++;
                update(0, 1, n, firstAvailable);
            }
        }
        return cnt;
    }
};
