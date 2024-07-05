class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> umap({{0, 1}});
        int ans = 0;
        for(int i = 0, c = 0; i < nums.size(); i++) {
            c += nums[i];
            ans += umap[c - goal];
            umap[c]++;
        }
        return ans;
    }
};