class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end()), ans = 0;
        vector<int> map(mx + 1);
        for (auto num : nums) {
            map[num]++;
        }
        for (int i = 0; i < mx; i++) {
            if (map[i] > 1) {
                int temp = map[i] - 1;
                ans += temp;
                map[i + 1] += temp;
            }
        }
        ans += (map[mx] * (map[mx] - 1)) / 2;
        return ans;
    }
};
