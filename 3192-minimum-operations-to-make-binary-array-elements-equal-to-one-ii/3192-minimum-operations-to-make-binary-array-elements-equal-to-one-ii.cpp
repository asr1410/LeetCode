class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flips = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if((nums[i] == 0 and flips % 2 == 0) or (nums[i] == 1 and flips % 2 == 1)) {
                flips++;
                ans++;
            }
        }
        return ans;
    }
};