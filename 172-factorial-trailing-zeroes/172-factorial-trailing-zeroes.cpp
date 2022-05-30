class Solution {
public:
    int a = 1;
    int trailingZeroes(int n) {
        if(n/a < 1)
            return 0;
        a *= 5;
        return (n/a) + trailingZeroes(n);
    }
};