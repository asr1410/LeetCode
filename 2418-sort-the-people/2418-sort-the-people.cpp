class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, int>> order;
        vector<string> ans;
        int n = heights.size();
        order.reserve(n);
        ans.reserve(n);
        for (int i = 0; i < n; i++) {
            order.emplace_back(heights[i], i);
        }
        sort(order.begin(), order.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        for (int i = 0; i < n; i++) {
            ans.emplace_back(names[order[i].second]);
        }
        return ans;
    }
};