#define mod 1000000007
class Solution {
public:
    long long power(long long x, long long y) {
        if(y == 0) {
            return 1;
        }
        long long ans = power(x, y / 2);
        ans = (ans * ans) % mod; // Ensure multiplication does not overflow before applying mod
        if(y % 2) {
            ans = (ans * x) % mod; // Apply mod after multiplication for the same reason
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = n - odd;
        // The correction is in the calculation of power for even places. It should be power(4, odd) instead of power(5, odd)
        // because even positions can have one of the 5 prime numbers (2, 3, 5, 7, 11), and odd positions can have one of the 4 even digits (0, 2, 4, 6, 8).
        return (power(5, even) * power(4, odd)) % mod;
    }
};