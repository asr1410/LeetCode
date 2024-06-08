class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        umap[0] = -1; // Initialize to handle the case where the subarray starts from index 0
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            count += nums[i];
            int mod = count % k;
            if (mod < 0) mod += k; // Handle negative remainders
            
            if(umap.find(mod) != umap.end()) {
                if(i - umap[mod] >= 2) { // Ensure subarray length is at least 2
                    return true;
                }
            } else {
                umap[mod] = i;
            }
        }
        return false;
    }
};
