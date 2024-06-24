class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(nums[i] == 0) {
                for(int j = i; j < i + 3; j++) {
                    nums[j] = nums[j] ^ 1;
                }
                ans++;
            }
        }
        return nums[nums.size() - 1] == 0 or nums[nums.size() - 2] == 0 ? -1 : ans;
    }
};