class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long added = 0, miss = 1, i = 0;
        while(miss <= n) {
            if(i < nums.size() and nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                added++;
            }
        }
        return added;
    }
};