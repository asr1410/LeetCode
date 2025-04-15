class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums2.size(); i++) {
            umap[nums2[i]] = i;
        }

        long long ans = 0;
        int n = nums1.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (umap[nums1[i]] > umap[nums1[j]]) continue;

                for (int k = j + 1; k < n; k++) {
                    if (umap[nums1[j]] < umap[nums1[k]]) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
