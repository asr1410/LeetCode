class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size(), ans = 0;
      for(int i = 0, mn = prices[0]; i < n; i++) {
        ans = max(ans, prices[i] - mn);
        mn = min(mn, prices[i]);
      }
      return ans;
    }
};