class Solution {
public:
    long long findMaximumScore(vector<int>& A) {
        long long res = 0;
        int ma = 0;
        for (int a: A) {
            res += ma;
            ma = max(ma, a);
        }
        return res;
    }
};