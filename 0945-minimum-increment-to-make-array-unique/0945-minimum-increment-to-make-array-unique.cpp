class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> map(100001, 0);
        for(auto num : nums) {
            map[num]++;
        }

        int ans = 0;

        for(int i = 0; i < 100000; i++) {
                int temp = max(0, map[i] - 1);
                ans += temp;
                map[i + 1] += temp;
        }

        ans += (map[100000] * (map[100000] - 1)) / 2;

        return ans;
    }
};
