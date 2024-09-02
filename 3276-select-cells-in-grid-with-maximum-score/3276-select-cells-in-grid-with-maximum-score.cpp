class Solution {
public:
    int helper(int n, int mask, vector<pair<int, int>>& vp,  map<pair<int, int>, int>& mp) {
        if(n < 0) {
            return 0;
        }
        if(mp.find({n, mask})!= mp.end())
            return mp[{n, mask}];
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
        return mp[make_pair(n, mask)] = ans;
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
        map<pair<int, int>, int> mp;
        return helper(rows * cols - 1, 0, vp, mp);
    }
};