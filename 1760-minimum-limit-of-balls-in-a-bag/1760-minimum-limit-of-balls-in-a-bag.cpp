class Solution {
public:
    bool possible(vector<int>& nums, int m, int o) {
        int cnt = 0;
        for (int& num : nums) {
            cnt += (num + m - 1) / m - 1;
        }
        return cnt <= o;
    }

    int minimumSize(vector<int>& nums, int mo) {
        int l = 1, r = *max_element(nums.begin(), nums.end()), ans = r;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (possible(nums, m, mo)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};