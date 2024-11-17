class Solution {
public:
    int helper(int i, int move, vector<int>& nums) {
        if (i < 0 || i == nums.size()) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] != 0) {
                    return 0;
                }
            }
            return 1;
        }
        int ans = 0;
        if (nums[i] == 0) {
            ans = helper(i + move, move, nums);
        } else {
            nums[i]--;
            ans = helper(i - move, -move, nums);
            nums[i]++;
        }
        return ans;
    }

    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                ans += helper(i - 1, -1, nums);
                ans += helper(i + 1, 1, nums);
            }
        }
        return ans;
    }
};