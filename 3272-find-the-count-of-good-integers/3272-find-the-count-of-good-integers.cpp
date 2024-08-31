class Solution {
   public:
    long long countGoodIntegers(int n, int k) {
        vector<vector<long long>> C(12, vector<long long>(12));
        C[0][0] = 1;
        for (int i = 1; i <= 11; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            }
        }
        long long res = 0;
        set<string> st;
        function<void(string, int)> dfs = [&](string s, int l) {
            if (l > n - 1 - l) {
                long long x = stoll(s);
                if (x % k == 0) {
                    sort(s.begin(), s.end());
                    if (st.count(s)) {
                        return;
                    }
                    st.emplace(s);
                    vector<int> c(10);
                    for (char t : s) {
                        c[t - '0']++;
                    }
                    long long w = C[n - 1][c[0]];
                    int z = n - c[0];
                    for (int i = 1; i <= 9; i++) {
                        w *= C[z][c[i]];
                        z -= c[i];
                    }
                    res += w;
                }
                return;
            }
            for (char c = (l == 0 ? '1' : '0'); c <= '9'; c++) {
                s[l] = s[n - 1 - l] = c;
                dfs(s, l + 1);
            }
        };
        dfs(string(n, '?'), 0);
        return res;
    }
};