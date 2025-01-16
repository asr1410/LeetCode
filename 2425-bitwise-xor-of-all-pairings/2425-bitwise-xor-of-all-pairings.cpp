class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int l1 = nums1.size(), l2 = nums2.size();
        if(l1 & 1) {
            for(int num : nums2) {
                ans ^= num;
            }
        }
        if(l2 & 1) {
            for(int num : nums1) {
                ans ^= num;
            }
        }
        return ans;
    }
};