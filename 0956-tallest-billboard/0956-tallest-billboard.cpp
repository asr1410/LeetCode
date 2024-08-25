class Solution {
public:
    int tallestBillboard(vector<int>& arr) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        
        for (int num : arr) {
            unordered_map<int, int> temp = dp;
            for (auto &[diff, height] : dp) {
                temp[diff + num] = max(temp[diff + num], height);
                temp[abs(diff - num)] = max(temp[abs(diff - num)], height + min(num, diff));
            }
            dp = temp;
        }
        
        return dp[0];
    }
};
