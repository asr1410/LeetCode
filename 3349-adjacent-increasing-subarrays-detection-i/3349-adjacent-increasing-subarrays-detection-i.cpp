class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i <= n - 2 * k; i++) {
            int fl = 0, sl = 0;
            for(int j = i; j < i + k - 1; j++) {
                if(nums[j] < nums[j + 1]) {
                    fl++;
                }
            }
            for(int j = i + k; j < i + 2 * k - 1; j++) {
                if(nums[j] < nums[j + 1]) {
                    sl++;
                }
            }
            if(fl == k - 1 && sl == k - 1) {
                return true;
            }
        }
        return false;
    }
};
