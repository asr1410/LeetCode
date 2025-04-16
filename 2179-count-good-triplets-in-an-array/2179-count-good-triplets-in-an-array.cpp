class SegmentTree {
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void update(int idx, int val, int node, int start, int end) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(idx, val, 2 * node + 1, start, mid);
            else
                update(idx, val, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
 
    int query(int l, int r, int node, int start, int end) {
        if (l > end || r < start) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftSum = query(l, r, 2 * node + 1, start, mid);
        int rightSum = query(l, r, 2 * node + 2, mid + 1, end);
        return leftSum + rightSum;
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void update(int idx, int val) {
        update(idx, val, 0, 0, n - 1);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, n - 1);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        int n = nums1.size();

        for (int i = 0; i < n; i++) mpp[nums1[i]] = i;
        for (int i = 0; i < n; i++) nums2[i] = mpp[nums2[i]];

        vector<int> leftArr(n, 0), rightArr(n, 1);
        SegmentTree leftTree(leftArr), rightTree(rightArr);

        leftTree.update(nums2[0], 1);
        rightTree.update(nums2[0], 0);

        long long total = 0;
        for (int i = 1; i < n - 1; i++) {
            int idx = nums2[i];
            rightTree.update(idx, 0);
            int left = leftTree.query(0, idx - 1);
            int right = rightTree.query(idx + 1, n - 1);
            total += (long long)left * right;
            leftTree.update(idx, 1);
        }
        return total;
    }
};