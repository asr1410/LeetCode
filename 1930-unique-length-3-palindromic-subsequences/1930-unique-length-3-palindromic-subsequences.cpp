class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<pair<int, int>> mark;
        for(int i = 0; i < 26; i++) {
            mark.push_back(make_pair(INT_MAX, INT_MIN));
        }
        vector<vector<int>> mat(n, vector<int> (26, 0));
        for(int i = 0; i < n; i++) {
            mat[i][s[i] - 'a'] = 1;
            mark[s[i] - 'a'].first = min(mark[s[i] - 'a'].first, i);
            mark[s[i] - 'a'].second = max(mark[s[i] - 'a'].second, i);
            if(i != 0) {
                for(int j = 0; j < 26; j++) {
                    mat[i][j] += mat[i - 1][j];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(mark[i].first != INT_MAX and mark[i].second != INT_MIN and mark[i].first != mark[i].second) {
                for(int j = 0; j < 26; j++) {
                    if(mat[mark[i].second - 1][j] - mat[mark[i].first][j]) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};