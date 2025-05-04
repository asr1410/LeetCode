class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX, n = tops.size();
        for(int i = 1; i <= 6; i++) {
            int tc = 0, bc = 0, ts = 0, bs = 0;
            for(int j = 0; j < n; j++) {
                if(tops[j] == i) {
                    tc++;
                } else if(bottoms[j] == i) {
                    bs++;
                }
            }
            if(tc + bs == n) {
                ans = min(ans, bs);
            }

            for(int j = 0; j < n; j++) {
                if(bottoms[j] == i) {
                    bc++;
                } else if(tops[j] == i) {
                    ts++;
                }
            }
            if(bc + ts == n) {
                ans = min(ans, ts);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};