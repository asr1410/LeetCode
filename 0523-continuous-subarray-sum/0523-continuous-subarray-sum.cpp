class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        umap[0] = -1;
        for(int i = 0, count = 0; i < nums.size(); i++) {
            count += nums[i];
            int mod = count % k;
            // if (mod < 0) mod += k;
            if(umap.find(mod) != umap.end()) {
                if(i - umap[mod] >= 2) {
                    return true;
                }
            } else {
                umap[mod] = i;
            }
        }
        return false;
    }
};
