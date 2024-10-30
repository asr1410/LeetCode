class Solution {
public:
    int lhelper(int i, int n, vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int j = 1; j <= i; j++) {
            if(temp.back() < nums[j]) {
                temp.push_back(nums[j]);
            } else {
                int idx = lower_bound(temp.begin(), temp.end(), nums[j]) - temp.begin();
                temp[idx] = nums[j];
            }
        }
        return temp.size();
    }
    int rhelper(int i, int n, vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[n - 1]);
        for(int j = n - 2; j >= i; j--) {
            if(temp.back() < nums[j]) {
                temp.push_back(nums[j]);
            } else {
                int idx = lower_bound(temp.begin(), temp.end(), nums[j]) - temp.begin();
                temp[idx] = nums[j];
            }
        }
        return temp.size();
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        for(int i = 1; i < n - 1; i++) {
            int l = lhelper(i, n, nums) - 1;
            int r = rhelper(i, n, nums) - 1;
            if(l > 0 and r > 0) {
                ans = min(ans, n - l - r - 1);
            }
        }
        return ans;
    }
};