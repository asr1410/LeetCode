class Solution {
private:
    int cache[501][501][3];
    int f(vector<vector<int>>& coins, int i, int j, int neu){
        int n = coins.size();
        int m = coins[0].size();
        if(i == n - 1 && j == m - 1){
            if(neu > 0 && coins[i][j] < 0){
                return 0;
            }else{
                return coins[i][j];
            }
        }
        if(i >= n || j>= m){
            return INT_MIN;
        }
        if (cache[i][j][neu] != INT_MIN) {
            return cache[i][j][neu];
        }
        int take = INT_MIN;int nottake = INT_MIN;
        take = coins[i][j] + max(f(coins, i + 1, j, neu), f(coins, i, j + 1, neu));
        if(neu > 0 && coins[i][j] < 0)
            nottake =  max(f(coins, i + 1, j, neu - 1), f(coins, i, j + 1, neu - 1));
        return cache[i][j][neu] = max(take, nottake);
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
    for (int i = 0; i < 501; ++i)
        for (int j = 0; j < 501; ++j)
            for (int k = 0; k < 3; ++k)
                cache[i][j][k] = INT_MIN;
        return f(coins, 0, 0, 2);
    }
};