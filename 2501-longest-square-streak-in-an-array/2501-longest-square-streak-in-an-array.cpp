class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, int> umap;
        sort(nums.begin(), nums.end());
        for(int num : nums) {
            int half = sqrt(num);
            if(half * half == num && umap.find(half) != umap.end()) {
                umap[num] = umap[half] + 1;
            } else {
                umap[num] = 1;
            }
        }
        
        int maxStreak = 0;
        for(auto it : umap) {
            maxStreak = max(maxStreak, it.second);
        }
        
        return maxStreak <= 1 ? -1 : maxStreak;
    }
};