class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int i = 0, j = 0, ni = g.size(), nj = s.size();
        while(i < ni && j < nj) {
            ans += g[i] <= s[j] and ++i;
            j++;
        }
        return ans;
    }
};