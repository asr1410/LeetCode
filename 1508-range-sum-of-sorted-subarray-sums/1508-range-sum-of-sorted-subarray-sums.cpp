class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int mod = 1e9 + 7;
        priority_queue<int> pq;
        for(int i = 0; i < n; i++) {
            for(int j = i, tsum = 0; j < n; j++) {
                tsum += nums[j];
                pq.emplace(tsum);
                if(pq.size() > right) {
                    pq.pop();
                }
            }
        }
        int ans = 0;
        for(int i = left; i <= right; i++) {
            ans = (ans + pq.top()) % mod;
            pq.pop();
        }
        return ans;
    }
};