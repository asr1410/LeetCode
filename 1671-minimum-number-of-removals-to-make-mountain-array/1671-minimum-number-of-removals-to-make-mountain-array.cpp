#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int lhelper(int i, const std::vector<int>& nums) {
        std::vector<int> temp;
        for (int j = 0; j <= i; j++) {
            if (temp.empty() || temp.back() < nums[j]) {
                temp.push_back(nums[j]);
            } else {
                int idx = std::lower_bound(temp.begin(), temp.end(), nums[j]) - temp.begin();
                temp[idx] = nums[j];
            }
        }
        return temp.size();  // Return the size of the longest increasing subsequence
    }

    int rhelper(int i, const std::vector<int>& nums) {
        std::vector<int> temp;
        for (int j = nums.size() - 1; j >= i; j--) {
            if (temp.empty() || temp.back() < nums[j]) {
                temp.push_back(nums[j]);
            } else {
                int idx = std::lower_bound(temp.begin(), temp.end(), nums[j]) - temp.begin();
                temp[idx] = nums[j];
            }
        }
        return temp.size();  // Return the size of the longest increasing subsequence
    }

    int minimumMountainRemovals(std::vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            int l = lhelper(i, nums) - 1;  // Exclude the peak
            int r = rhelper(i, nums) - 1;  // Exclude the peak
            if (l > 0 && r > 0) {  // Both sides must have increasing sequences
                ans = std::min(ans, n - l - r - 1);  // Total removals to form a mountain
            }
        }
        return ans == INT_MAX ? 0 : ans;  // If no valid mountain found, return 0
    }
};
