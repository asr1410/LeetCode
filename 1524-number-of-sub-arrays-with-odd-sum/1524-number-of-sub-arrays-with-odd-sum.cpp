class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> dpEven(n, 0), dpOdd(n, 0);

        if (arr[0] % 2 == 0) {
            dpEven[0] = 1;
        } else {
            dpOdd[0] = 1;
        }

        for (int i = 1; i < n; i++) {
            if (arr[i] % 2 == 1) {
                dpOdd[i] = (1 + dpEven[i - 1]) % MOD;
                dpEven[i] = dpOdd[i - 1];
            } else {
                dpOdd[i] = dpOdd[i - 1];
                dpEven[i] = (1 + dpEven[i - 1]) % MOD;
            }
        }

        int count = 0;
        for (int oddCount : dpOdd) {
            count = (count + oddCount) % MOD;
        }

        return count;
    }
};
