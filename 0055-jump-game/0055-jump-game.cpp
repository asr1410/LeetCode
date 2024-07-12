class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), i = 0;
        for(int reach = 0; i < n and i <= reach; i++) {
            reach = max(reach, i + nums[i]);
        }
        return i == n;
    }
};