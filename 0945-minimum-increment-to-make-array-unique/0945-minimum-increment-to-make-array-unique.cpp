class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> map(mx + 1);
        for(auto num : nums) {
            map[num]++;
        }

        int ans = 0;

        for(int i = 0; i < mx; i++) {
            int temp = max(0, map[i] - 1);
            ans += temp;
            map[i + 1] += temp;
        }

        ans += (map[mx] * (map[mx] - 1)) / 2;

        return ans;
    }
};
