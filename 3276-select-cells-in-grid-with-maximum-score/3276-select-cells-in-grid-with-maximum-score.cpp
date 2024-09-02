class Solution {
public:
    int helper(int n, int mask, vector<pair<int, int>>& vp,  unordered_map<int, int>& mp) {
        if(n < 0) {
            return 0;
        }
        if(mp.find((n << 11) | mask)!= mp.end())
            return mp[(n << 11) | mask];
        int ans = 0;
        if((1 << vp[n].second) & mask) {
            ans = helper(n - 1, mask, vp, mp);
        } else {
            int j = n;
            while(j >= 0 and vp[n].first == vp[j].first) {
                j--;
            }
            ans = max(vp[n].first + helper(j, (1 << vp[n].second) | mask, vp, mp), helper(n - 1, mask, vp, mp));
        }
        return mp[(n << 11) | mask] = ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        vector<pair<int, int>> vp;
        int rows = grid.size(), cols = grid[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                vp.push_back(make_pair(grid[i][j], i));
            }
        }
        sort(vp.begin(), vp.end());
        unordered_map<int, int> mp;
        return helper(rows * cols - 1, 0, vp, mp);
    }
};