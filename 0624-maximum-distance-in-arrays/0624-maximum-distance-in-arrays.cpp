class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0, mn = arrays[0][0], mx = arrays[0][arrays[0].size() - 1];
        for(int i = 1; i < arrays.size(); i++) {
            ans = max(ans, abs(mn - arrays[i][arrays[i].size() - 1]));
            ans = max(ans, abs(mx - arrays[i][0]));
            mn = min(mn, arrays[i][0]);
            mx = max(mx, arrays[i][arrays[i].size() - 1]);
        }
        return ans;
    }
};