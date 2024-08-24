class Solution {
public:
    vector<int> seg;

    void update(int idx, int low, int high, int pos) {
        if (low == high) {
            seg[idx]++;
            return;
        }
        int mid = (low + high) >> 1;
        if (pos <= mid) {
            update(2 * idx + 1, low, mid, pos);
        } else {
            update(2 * idx + 2, mid + 1, high, pos);
        }
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int l, int r) {
        if (r < low || l > high) {
            return 0;
        }
        if (l <= low && high <= r) {
            return seg[idx];
        }
        int mid = (low + high) >> 1;
        return query(2 * idx + 1, low, mid, l, r) + query(2 * idx + 2, mid + 1, high, l, r);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int minValue = *min_element(nums.begin(), nums.end());
        int maxValue = *max_element(nums.begin(), nums.end());
        int offset = minValue < 0 ? -minValue : 0;
        int range = maxValue + offset;
        seg.resize(4 * (range + 1), 0);
        vector<int> result(nums.size(), 0);

        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] = query(0, 0, range, 0, nums[i] + offset - 1);
            update(0, 0, range, nums[i] + offset);
        }

        return result;
    }
};