class Solution {
public:
    int atmost(vector<int> &nums, int k) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> umap;
        for (int l = 0, r = 0; r < n; r++) {
            umap[nums[r]]++;
            while (umap.size() > k) {
                umap[nums[l]]--;
                if (umap[nums[l]] == 0) {
                    umap.erase(nums[l]);
                }
                l++;
            }
            ans += (r - l + 1);
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};
