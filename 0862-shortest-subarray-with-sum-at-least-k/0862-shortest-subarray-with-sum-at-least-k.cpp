#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        
        // Calculate the prefix sums
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        deque<int> dq; // deque of indices
        
        int minLength = n + 1; // initialize to a large value
        
        for (int i = 0; i <= n; ++i) {
            // Maintain the deque in increasing order of prefix sums indices
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                minLength = min(minLength, i - dq.front());
                dq.pop_front();
            }
            
            // Maintain the deque in increasing order of prefix sums indices
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        return minLength == n + 1 ? -1 : minLength;
    }
};
