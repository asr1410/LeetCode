class Solution {
public:
    long long lcmf(int i, int n, vector<int> nums) {
        long long ans = 1;
        for(int j = 2; j < 31; j++) {
            int cnt = 0;
            for(int k = 0; k < n; k++) {
                if(i != k) {
                    int t = 0, val = nums[k];
                    while(val % j == 0) {
                        t++;
                        val /= j;
                    }
                    nums[k] = val;
                    cnt = max(cnt, t);
                }
            }
            ans *= pow(j, cnt);
        }
        return ans;
    }
    long long gcdf(int i, int n, vector<int>& nums) {
        long long ans = 1;
        for(int j = 2; j < 31; j++) {
            int cnt = 0;
            for(int k = 0; k < n; k++) {
                if(i != k and nums[k] % j == 0) {
                    cnt++;
                }
            }
            if((i == -1 and cnt == n) or (i != -1 and cnt == n - 1)) {
                ans = j;
            }
        }
        return ans;
    }
    long long maxScore(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0] * nums[0];
        }
        long long ans = 0;
        int n = nums.size();
        for(int i = -1; i < n; i++) {
            long long l = lcmf(i, n, nums);
            long long g = gcdf(i, n, nums);
            ans = max(ans, l * g);
        }
        return ans;
    }
};