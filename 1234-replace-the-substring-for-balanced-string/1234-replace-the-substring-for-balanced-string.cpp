class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> umap;
        int n = s.size();
        int limit = n / 4;
        for (char c : s) {
            umap[c]++;
        }
        int qc = max(0, umap['Q'] - limit);
        int wc = max(0, umap['W'] - limit);
        int ec = max(0, umap['E'] - limit);
        int rc = max(0, umap['R'] - limit);
        if (qc == 0 && wc == 0 && ec == 0 && rc == 0) {
            return 0;
        }
        int ans = n;
        unordered_map<char, int> window;
        int j = 0;
        for (int i = 0; i < n; i++) {
            window[s[i]]++;
            while (window['Q'] >= qc && window['W'] >= wc && window['E'] >= ec && window['R'] >= rc) {
                window[s[j]]--;
                ans = min(ans, i - j + 1);
                j++;
            }
        }
        return ans;
    }
};
