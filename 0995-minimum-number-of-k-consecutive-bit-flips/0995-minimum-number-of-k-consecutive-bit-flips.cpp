class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<int> flipCount(nums.size());
        int flips = 0, ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i >= k) {
                flips -= flipCount[i - k];
            }
            if((nums[i] == 0 and flips % 2 == 0) or (nums[i] == 1 and flips % 2 == 1)) {
                if(i + k - 1 >= n) {
                    return -1;
                } else {
                    ans++;
                    flips++;
                    flipCount[i] = 1;
                }
            }
        }
        return ans;
    }
};