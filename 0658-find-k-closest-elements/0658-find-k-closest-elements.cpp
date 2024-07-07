class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < k; i++) {
            pq.push({abs(nums[i] - x), nums[i]});
        }
        
        for(int i = k; i < nums.size(); i++) {
            if(abs(nums[i] - x) < pq.top().first) {
                pq.pop();
                pq.push({abs(nums[i] - x), nums[i]});
            } else if(abs(nums[i] - x) == pq.top().first and nums[i] < pq.top().second) {
                pq.pop();
                pq.push({abs(nums[i] - x), nums[i]});
            }
        }
        
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};