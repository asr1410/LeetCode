class SegmentTree {
public:
    vector<int> seg;

    void build(int idx, int low, int high, const vector<int>& arr) {
        if (low == high) {
            seg[idx] = arr[low];
        } else {
            int mid = (low + high) >> 1;
            build(2 * idx + 1, low, mid, arr);
            build(2 * idx + 2, mid + 1, high, arr);
            seg[idx] = (seg[2 * idx + 1] + seg[2 * idx + 2]);
        }
    }

    int query(int idx, int low, int high, int l, int r) {
        if (r < low || high < l) return 0;
        if (low >= l && high <= r) return seg[idx];
        int mid = (low + high) >> 1;
        return (query(2 * idx + 1, low, mid, l, r) + query(2 * idx + 2, mid + 1, high, l, r));
    }
};

class NumArray {
public:
    SegmentTree st;
    int len = 0;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        len = n;
        st.seg.resize(4 * n);
        st.build(0, 0, n - 1, nums);
    }
    
    int sumRange(int left, int right) {
        return st.query(0, 0, len - 1, left, right);
    }
};