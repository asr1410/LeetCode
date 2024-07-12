class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int i = 0, j = 0, ni = g.size(), nj = s.size();
        while(i < ni and j < nj) {
            if(g[i] <= s[j]) {
                ans++, i++;
            }
            j++;
        }
        return ans;
    }
};