#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void buildFactorials(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        invFact[n] = modPow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; --i)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    long long comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int idealArrays(int n, int maxValue) {
        buildFactorials(n);
        long long ans = maxValue;
        unordered_map<int, long long> freq;
        for (int i = 1; i <= maxValue; ++i) {
            freq[i] = 1;
        }

        for (int k = 1; k < n; ++k) {
            if (freq.empty()) break;
            unordered_map<int, long long> temp;
            for (const auto& [x, count] : freq) {
                for (int m = 2; m * x <= maxValue; ++m) {
                    int nextVal = m * x;
                    ans = (ans + comb(n - 1, k) * count % MOD) % MOD;
                    temp[nextVal] = (temp[nextVal] + count) % MOD;
                }
            }
            freq = move(temp);
        }
        return static_cast<int>(ans);
    }
};
