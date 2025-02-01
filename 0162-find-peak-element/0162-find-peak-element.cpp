class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1 or nums[0] > nums[1]) {
            return 0;
        }
        int n = nums.size();
        if(nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }
        int l = 1, r = n - 2;
        while(l < r) {
            int m = (l + r) >> 1;
            if(nums[m] < nums[m + 1]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};