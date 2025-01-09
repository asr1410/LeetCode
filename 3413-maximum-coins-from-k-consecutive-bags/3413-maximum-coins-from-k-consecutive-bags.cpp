class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        long long res = 0, cur = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && coins[j][1] - coins[i][0] + 1 <= k) {
                cur += 1L * (coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }
            if (j < n) {
                long long part = 1L * max(0, coins[i][0]- coins[j][0] + k) * coins[j][2];
                res = max(res, cur + part);
            }
            cur -= 1L * (coins[i][1] - coins[i][0] + 1) * coins[i][2];
        }
        cur = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            cur += 1L * (coins[i][1] - coins[i][0] + 1) * coins[i][2];
            while (k < coins[i][1] - coins[j][1] + 1) {
                cur -= 1L * (coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }
            long long part = 1L * max(0, coins[i][1] - k - coins[j][0] + 1) * coins[j][2];
            res = max(res, cur - part);
        }

        return res;
    }
};