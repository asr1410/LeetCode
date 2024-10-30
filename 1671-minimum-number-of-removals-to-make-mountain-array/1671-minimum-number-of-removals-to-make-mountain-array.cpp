class Solution {
public:
    int lhelper(int i, vector<int>& nums) {
        vector<int> temp;
        for (int j = 0; j <= i; j++) {
            if (temp.empty() || temp.back() < nums[j]) {
                temp.push_back(nums[j]);
            } else {
                int idx = lower_bound(temp.begin(), temp.end(), nums[j]) - temp.begin();
                temp[idx] = nums[j];
            }
        }
        return temp.size();
    }

    int rhelper(int i, vector<int>& nums) {
        vector<int> temp;
        for (int j = nums.size() - 1; j >= i; j--) {
            if (temp.empty() || temp.back() < nums[j]) {
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
        for (int i = 1; i < n - 1; i++) {
            int l = lhelper(i, nums) - 1;
            int r = rhelper(i, nums) - 1;
            if (l > 0 && r > 0) {
                ans = min(ans, n - l - r - 1);
            }
        }
        return ans;
    }
};
