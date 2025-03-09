class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int oc = 0, n = blocks.size();
        for(int i = 0; i < k; i++) {
            oc += blocks[i] != 'B';
        }
        int ans = oc;
        for(int i = k, j = 0; i < n; i++, j++) {
            oc -= blocks[j] != 'B';
            oc += blocks[i] != 'B';
            ans = min(ans, oc);
        }
        return ans;
    }
};