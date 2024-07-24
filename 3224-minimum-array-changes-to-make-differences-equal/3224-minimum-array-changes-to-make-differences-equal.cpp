class Solution {
public:
    int minChanges(vector<int>& a, int k) {
        int n = a.size(), h = n >> 1;
        vector<int> absdiff(k + 1), maxdiff(k + 1);
        for(int i = 0; i < h; i++) {
            absdiff[abs(a[i] - a[n - i - 1])]++;
            maxdiff[max(max(a[i], a[n - i - 1]), k - min(a[i], a[n - i - 1]))]++;
        }
        for(int i = 1, j = 0; i <= k; i++, j++) {
            maxdiff[i] += maxdiff[j];
        }
        int ans = h - absdiff[0];
        for(int i = 1, j = 0; i <= k; i++, j++) {
            ans = min(ans, h - absdiff[i] + maxdiff[j]);
        }
        return ans;
    }
};