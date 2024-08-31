class MyCalendarThree {
public:
    unordered_map<int, int> seg;
    unordered_map<int, int> lazy;
    
    MyCalendarThree() {}

    void update(int idx, int low, int high, int l, int r) {
        if (lazy[idx] != 0) {
            seg[idx] += lazy[idx];
            if (low != high) {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if (l > high || r < low) return;
        if (l <= low && high <= r) {
            seg[idx] += 1;
            if (low != high) {
                lazy[2 * idx + 1] += 1;
                lazy[2 * idx + 2] += 1;
            }
            return;
        }
        int mid = (low + high) >> 1;
        update(2 * idx + 1, low, mid, l, r);
        update(2 * idx + 2, mid + 1, high, l, r);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int book(int startTime, int endTime) {
        update(0, 0, 1000000000, startTime, endTime - 1);
        return seg[0];
    }
};
