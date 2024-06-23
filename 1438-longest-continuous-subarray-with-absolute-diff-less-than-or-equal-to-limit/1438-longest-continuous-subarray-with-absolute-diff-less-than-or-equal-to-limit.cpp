class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), i = 0, j = 0, ans = 0;
        priority_queue<pair<int, int>> mx;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mn;
        
        while(j < n) {
            mx.push({nums[j], j});
            mn.push({nums[j], j});
            while(mx.top().first - mn.top().first > limit) {
                i++;
                while(!mx.empty() && mx.top().second < i) mx.pop();
                while(!mn.empty() && mn.top().second < i) mn.pop();
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        
        return ans;
    }
};