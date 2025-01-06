class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> mark(n + 1, 0);
        for (auto shift : shifts) {
            if (shift[2] == 0) {
                mark[shift[0]] -= 1;
                mark[shift[1] + 1] += 1;
            } else {
                mark[shift[0]] += 1;
                mark[shift[1] + 1] -= 1;
            }
        }
        for (int i = 1; i < n; i++) {
            mark[i] += mark[i - 1];
        }
        for (int i = 0; i < n; i++) {
            int val = ((mark[i] % 26) + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + val) % 26;
        }
        return s;
    }
};
