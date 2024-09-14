class Solution {
private:
    vector<int> seg;

    void build(int idx, int low, int high) {
        if (low == high) {
            seg[idx] = low;
        } else {
            int mid = (low + high) / 2;
            build(2 * idx + 1, low, mid);
            build(2 * idx + 2, mid + 1, high);
            seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
        }
    }

    void update(int idx, int low, int high, int pos) {
        if (low == high) {
            seg[idx] = INT_MAX;
        } else {
            int mid = (low + high) / 2;
            if (pos <= mid) {
                update(2 * idx + 1, low, mid, pos);
            } else {
                update(2 * idx + 2, mid + 1, high, pos);
            }
            seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
        }
    }

    int getFirstAvailable(int idx, int low, int high, int l, int r) {
        if(r < low or l > high) {
            return INT_MAX;
        }
        if (l <= low && high <= r) {
            return seg[idx];
        }
        int mid = (low + high) >> 1;
        return min(getFirstAvailable(2 * idx + 1, low, mid, l, r), getFirstAvailable(2 * idx + 2, mid + 1, high, l, r));
    }

public:
    int maxEvents(vector<vector<int>>& events) {
        int n = 100000;
        seg.resize(4 * n);
        build(0, 1, n);

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
