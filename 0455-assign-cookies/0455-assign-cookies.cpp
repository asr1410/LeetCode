class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, ni = g.size(), nj = s.size();
        while(i < ni && j < nj) {
            i += g[i] <= s[j++];
        }
        return i;
    }
};