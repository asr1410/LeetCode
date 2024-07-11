class Solution {
public:
    int minMoves(vector<int>& nums) {
        unsigned int ans = 0, mn = *min_element(nums.begin(), nums.end());
        for(auto num:nums) ans += (num - mn);
        return ans;
    }
};