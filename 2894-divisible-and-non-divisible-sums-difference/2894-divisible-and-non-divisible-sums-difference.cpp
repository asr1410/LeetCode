class Solution {
public:
    int differenceOfSums(int n, int m) {
        int fs = 0, ss = 0;
        for(int i = 1; i <= n; i++) {
            fs += i % m == 0 ? 0 : i;
            ss += i % m == 0 ? i : 0;
        }
        return fs - ss;
    }
};