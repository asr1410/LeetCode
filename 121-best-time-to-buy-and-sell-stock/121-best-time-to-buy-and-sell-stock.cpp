class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
     int buy = INT_MAX;
     for (auto &&i : prices)
     {
          buy = min(buy, i);
          maxProfit = max(maxProfit, i - buy);
     }
     return maxProfit;
    }
};