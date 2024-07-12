class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, fpoint = 0, end = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            fpoint = max(fpoint, i + nums[i]);
            if(i == end) {
                ans++;
                end = fpoint;
            }
        }
        return ans;
    }
};