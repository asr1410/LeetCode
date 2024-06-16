class Solution {
public:
int minPatches(vector<int>& nums, int n) {
    int count = 0, i = 0;
    for (long miss=1; miss <= n; count++)
        miss += (i < nums.size() && nums[i] <= miss) ? nums[i++] : miss;
    return count - i;
}
};