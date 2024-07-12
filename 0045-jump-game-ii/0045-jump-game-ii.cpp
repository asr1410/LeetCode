class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, i = 0, n = nums.size();
        while(i < n - 1) {
            if(i + nums[i] >= n - 1) {
                return ans + 1;
            } else {
                int limit = i + nums[i], maxreach = limit + nums[limit], next = limit;
                for(int j = i + 1; j <= limit; j++) {
                    if(j + nums[j] > maxreach) {
                        maxreach = j + nums[j];
                        next = j;
                    }
                }
                i = next;
                ans++;
            }
        }
        return ans;
    }
};