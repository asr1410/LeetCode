class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<long long> t(4, INT_MIN);
        for (long long n : b) {
            t[3] = max(t[3], t[2] + n * a[3]);
            t[2] = max(t[2], t[1] + n * a[2]);
            t[1] = max(t[1], t[0] + n * a[1]);
            t[0] = max(t[0], n * a[0]);
        }
        return t[3];
    }
};