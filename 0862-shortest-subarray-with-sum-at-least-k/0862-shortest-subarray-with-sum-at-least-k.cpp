class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefix = 0;
        deque<pair<long long, int>> dq;
        dq.push_back({0, -1});
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            prefix += nums[i];
            while(dq.empty() == false and dq.back().first >= prefix) {
                dq.pop_back();
            }
            while(dq.empty() == false and prefix - k >= dq.front().first) {
                ans = min(ans, i - dq.front().second);
                dq.pop_front();
            }
            dq.push_back({prefix, i});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};