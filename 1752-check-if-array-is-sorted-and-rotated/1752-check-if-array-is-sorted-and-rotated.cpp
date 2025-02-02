class Solution {
public:
    bool check(const vector<int>& nums) {
        int n = nums.size(), k = 0;
        for(int i = 0; i < n; ++i) {
            k += nums[i] > nums[(i + 1) % n];
        }
        return k < 2;
    }
};