class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;
        for (const auto& d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            mp[{a, b}]++;
        }
        int ans = 0;
        for (const auto& [key, val] : mp) {
            ans += val * (val - 1) / 2;
        }
        return ans;
    }
};
