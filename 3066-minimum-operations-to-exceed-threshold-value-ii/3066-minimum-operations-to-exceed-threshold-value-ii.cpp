class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(const int& num : nums)
            pq.emplace(num);
        int ans = 0;
        while(pq.top() < k) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            pq.emplace(min(first, second) * 2 + max(first, second));
            ans++;
        }

        return ans;
    }
};