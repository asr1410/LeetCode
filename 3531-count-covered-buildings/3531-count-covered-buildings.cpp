#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> mxr(n + 1, 0), mxc(n + 1, 0), mnr(n + 1, INT_MAX), mnc(n + 1, INT_MAX);
        for (const auto& it : buildings) {
            mxr[it[0]] = max(mxr[it[0]], it[1]);
            mxc[it[1]] = max(mxc[it[1]], it[0]);
            mnr[it[0]] = min(mnr[it[0]], it[1]);
            mnc[it[1]] = min(mnc[it[1]], it[0]);
        }
        int ans = 0;
        for (const auto& it : buildings) {
            ans += (mxr[it[0]] > it[1] && mnr[it[0]] < it[1] && mxc[it[1]] > it[0] && mnc[it[1]] < it[0]);
        }
        return ans;
    }
};
