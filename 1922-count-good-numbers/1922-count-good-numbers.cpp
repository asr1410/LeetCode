class Solution {
public:
    long long powmod(long long a, long long b, long long mod) {
        long long result = 1;
        a %= mod;
        while (b > 0) {
            if (b & 1) {
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long mod = 1e9 + 7;
        long long even = 5, prime = 4, ans = 1, ecount = (n + 1LL) >> 1, ocount = n >> 1;
        return (powmod(even, ecount, mod) * powmod(prime, ocount, mod)) % mod;
    }
};