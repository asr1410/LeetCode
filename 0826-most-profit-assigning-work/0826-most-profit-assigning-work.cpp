class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> comb;
        for (int i = 0; i < profit.size(); i++) {
            comb.emplace_back(difficulty[i], profit[i]);
        }
        
        // Sort by difficulty, and if same difficulty then by profit descending
        sort(comb.begin(), comb.end());
        
        // Make sure we are tracking the max profit up to each point
        for (int i = 1; i < comb.size(); i++) {
            comb[i].second = max(comb[i].second, comb[i - 1].second);
        }
        
        int ans = 0;
        for (int i = 0; i < worker.size(); i++) {
            // Use binary search to find the maximum profit that a worker can get
            auto it = upper_bound(comb.begin(), comb.end(), make_pair(worker[i], INT_MAX)) - 1;
            if (it >= comb.begin()) {
                ans += it->second;
            }
        }
        
        return ans;
    }
};