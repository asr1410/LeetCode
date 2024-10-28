class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, int> umap;
        sort(nums.begin(), nums.end());
        for(int num : nums) {
            int half = sqrt(num);
            if(half * half == num and umap.find(half) != umap.end()) {
                umap[num] = umap[half] + 1;
            } else {
                umap[num] = 1;
            }
        }
        int ans = 0;
        for(auto it : umap) {
            ans = max(ans, it.second);
        }
        return ans == 1 ? -1 : ans;
    }
};