class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long ans = INT_MIN, temp = 1;
        for(int i = 0; i < nums.size(); i++) {
            temp = temp * nums[i];
            ans = max(ans, temp);
            if(temp == 0 or temp < -1e9) {
                temp = 1;
            }
        }
        temp = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            temp = temp * nums[i];
            ans = max(ans, temp);
            if(temp == 0 or temp < -1e9) {
                temp = 1;
            }
        }
        return ans;
    }
};