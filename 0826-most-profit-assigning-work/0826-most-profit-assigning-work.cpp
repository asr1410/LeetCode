class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> comb;
        for (int i = 0; i < profit.size(); i++) {
            comb.push_back(make_pair(difficulty[i], profit[i]));
        }
        sort(comb.begin(), comb.end());
        int ans = 0;
        for (int i = 0; i < worker.size(); i++) {
            int temp = 0;
            for (int j = 0; j < comb.size(); j++) {
                if (worker[i] >= comb[j].first && temp < comb[j].second) {
                    temp = comb[j].second;
                } else if (worker[i] < comb[j].first) {
                    break;
                }
            }
            ans += temp;
        }
        return ans;
    }
};
