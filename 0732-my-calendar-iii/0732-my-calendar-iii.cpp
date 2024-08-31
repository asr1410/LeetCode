class MyCalendarThree {
private:
    unordered_map<int, int> maxMap;  // To store the maximum overlap at each segment
    unordered_map<int, int> lazyMap; // To store the lazy propagation updates

    void update(int l, int r, int left, int right, int id) {
        if (right <= l || r <= left) return;
        if (l <= left && right <= r) {
            maxMap[id] += 1;
            lazyMap[id] += 1;
        } else {
            int md = (left + right) >> 1;
            int lc = id * 2;
            int rc = id * 2 + 1;
            update(l, r, left, md, lc);
            update(l, r, md, right, rc);
            maxMap[id] = lazyMap[id] + std::max(maxMap[lc], maxMap[rc]);
        }
    }

public:
    MyCalendarThree() {}

    int book(int start, int end) {
        update(start, end, 0, 1e9, 1);
        return maxMap[1];
    }
};
