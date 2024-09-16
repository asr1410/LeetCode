class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int na = a.size(), nb = b.size();
        vector<long long> curr(nb + 1, INT_MIN), prev(nb + 1, INT_MIN);
        for (int j = 0; j <= nb; j++) {
            prev[j] = 0;
        }
        for (int i = na - 1; i >= 0; i--) {
            for (int j = nb - 1; j >= 0; j--) {
                long long ntaken = curr[j + 1];
                long long taken = static_cast<long long>(a[i]) * b[j] + prev[j + 1];
                curr[j] = max(ntaken, taken);
            }
            prev = curr;
        }

        return curr[0];
    }
};
