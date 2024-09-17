class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(make_pair(nums[i], i));
            if(pq.size() > k) pq.pop();
        }
        vector<pair<int, int>> temp;
        while(pq.empty() == false) {
            temp.push_back(pq.top());
            pq.pop();
        }
        sort(temp.begin(), temp.end(), [](auto a, auto b) {
            return a.second < b.second;
        });
        vector<int> ans;
        for(auto t : temp) {
            ans.push_back(t.first);
        }
        return ans;
    }
};