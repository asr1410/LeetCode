class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, n = nums.size();
        while(i < n - 1) {
            if(nums[i] == 0) {
                return false;
            } else if(nums[i] + i >= n - 1) {
                return true;
            } else {
                int limit = nums[i] + i, next = limit, mreach = limit + nums[limit];
                for(int j = i + 1; j <= limit; j++) {
                    if(j + nums[j] > mreach) {
                        mreach = j + nums[j];
                        next = j;
                    }
                }
                i = next;
            }
        }
        return true;
    }
};