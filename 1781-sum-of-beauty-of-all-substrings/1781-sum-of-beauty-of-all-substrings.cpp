class Solution {
public:
    int maxdiff(unordered_map<char, int>& map) {
        int mx = INT_MIN, mn = INT_MAX;
        for(auto it:map) {
            mx = max(mx, it.second);
            mn = min(mn, it.second);
        }
        return mx - mn;
    }
    int beautySum(string s) {
        int count = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            unordered_map<char, int> map;
            for(int j = i; j < n; j++) {
                map[s[j]]++;
                count += maxdiff(map);
            }
        }
        return count;
    }
};