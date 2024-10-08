class Solution {
public:
    int change(int amount, vector<int>& coins) {
            int n = coins.size();
            if(amount == 0) return 1;
            if(n == 0) return 0;

            vector<vector<int>> dp(n, vector<int> (amount + 1, 0));
            for(int T = 0; T <= amount; T++ ){
                dp[0][T] = (T % coins[0] == 0);
            }

            for(int ind = 1; ind < n; ind++){
                for(int T = 0; T <= amount; T++){
                    long notTake = dp[ind - 1][T];
                    long take = 0;
                    if(T >= coins[ind]) take = dp[ind][T - coins[ind]];
                    dp[ind][T] = take + notTake;

                }
            }

            return dp[n - 1][amount];
        }
};