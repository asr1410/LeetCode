class Solution {
public:
    vector<int> fen;
    int size;
    int query(int idx) {
        int sum = 0;
        while(idx > 0) {
            sum += fen[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    void update(int idx) {
        while(idx < size) {
            fen[idx] += 1;
            idx += (idx & -idx);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int mn = abs(*min_element(nums.begin(), nums.end()));
        int mx = *max_element(nums.begin(), nums.end());
        size = mx + mn + 2;
        fen.resize(size, 0);
        vector<int> ans(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--) {
            ans[i] = query(nums[i] + mn);
            update(nums[i] + mn + 1);
        }
        return ans;
    }
};