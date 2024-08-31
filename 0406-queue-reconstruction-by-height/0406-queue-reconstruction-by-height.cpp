class ST {
public:
    vector<int> seg;
    ST(int n) {
        seg.resize(4 * n, 0);
    }
    
    void build(int idx, int low, int high) {
        if(low == high) {
            seg[idx] = 1;
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * idx + 1, low, mid);
        build(2 * idx + 2, mid + 1, high);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    
    void update(int idx, int low, int high, int pos) {
        if(low == high) {
            seg[idx] = 0;
            return;
        }
        int mid = (low + high) >> 1;
        if(pos <= mid) {
            update(2 * idx + 1, low, mid, pos);
        } else {
            update(2 * idx + 2, mid + 1, high, pos);
        }
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    
    int query(int idx , int low, int high, int pos) {
        if(low == high) {
            return low;
        }
        int mid = (low + high) >> 1;
        if(pos <= seg[2 * idx + 1]) {
            return query(2 * idx + 1, low, mid, pos);
        }
        return query(2 * idx + 2, mid + 1, high, pos - seg[2 * idx + 1]);
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](vector<int>& u, vector<int>& v) {
            return u[0] < v[0] or (u[0] == v[0] and u[1] > v[1]);
        });
        ST st(n);
        st.build(0, 0, n - 1);
        vector<vector<int>> ans(n, vector<int>{0, 0});
        for(int i = 0; i < n; i++) {
            int idx = st.query(0, 0, n - 1, people[i][1] + 1);
            ans[idx][0] = people[i][0];
            ans[idx][1] = people[i][1];
            st.update(0, 0, n - 1, idx);
        }
        return ans;
    }
};