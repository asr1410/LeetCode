class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(umap.find(target - nums[i]) != umap.end()) {
                return {umap[target - nums[i]], i};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};