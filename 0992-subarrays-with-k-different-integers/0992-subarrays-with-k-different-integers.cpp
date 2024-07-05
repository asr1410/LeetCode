class Solution {
public:
    int atmost(vector<int> &nums, int k) {
        unordered_map<int, int> umap;
        int ans = 0;
        for(int l = 0, r = 0, count = 0; r < nums.size(); r++) {
            count += umap[nums[r]] == 0;
            umap[nums[r]]++;
            while(count > k) {
                umap[nums[l]]--;
                count -= umap[nums[l]] == 0;
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};