class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0 or n == INT_MIN) {
            return false;
        }
        return (n & (n - 1)) == 0;
    }
};