class SegmentTree {
private:
    vector<bool> tree;
    vector<bool> data;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] && tree[2 * node + 2];
        }
    }

    bool query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return true;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        bool leftQuery = query(2 * node + 1, start, mid, l, r);
        bool rightQuery = query(2 * node + 2, mid + 1, end, l, r);
        return leftQuery && rightQuery;
    }

public:
    SegmentTree(const vector<bool>& input) {
        n = input.size();
        data = input;
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    bool query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        if(nums.size() == 1) {
            vector<bool> ans;
            int n = queries.size();
            for(int i = 0; i < n; i++) {
                ans.push_back(true);
            }
            return ans;
        }
        vector<bool> flag(nums.size() - 1);
        for (int i = 0, j = 1; j < nums.size(); j++) {
            flag[j - 1] = ((nums[i] & 1) != (nums[j] & 1));
            i++;
        }
        SegmentTree st(flag);
        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(st.query(q[0], q[1] - 1));
        }
        return ans;
    }
};
