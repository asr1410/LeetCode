class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mark(n, 1);
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1] + 1) {
                mark[i] = mark[i - 1] + 1;
            }
        }
        vector<int> ans;
        for(int i = k - 1; i < n; i++) {
            if(mark[i] >= k) {
                ans.push_back(nums[i]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};