class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN;
        int curr = 0;
        for(auto &&i : nums)
        {
            curr = max(i+curr, i);
            mx = max(mx, curr);
        }
        return mx;
    }
};