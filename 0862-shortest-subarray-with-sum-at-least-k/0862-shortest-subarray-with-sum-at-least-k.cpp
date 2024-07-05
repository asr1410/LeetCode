class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1, j = 0; i < n; i++, j++) {
            prefix[i] = prefix[j] + nums[i];
        }
        deque<pair<long long, int>> dq;
        dq.push_back({0, -1});
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            while(dq.empty() == false and dq.back().first >= prefix[i]) {
                dq.pop_back();
            }
            while(dq.empty() == false and prefix[i] - k >= dq.front().first) {
                ans = min(ans, i - dq.front().second);
                dq.pop_front();
            }
            dq.push_back({prefix[i], i});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};