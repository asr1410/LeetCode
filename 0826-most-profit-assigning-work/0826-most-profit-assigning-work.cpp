class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        // Find maximum ability in the worker array.
        int maxAbility = *max_element(begin(worker), end(worker));
        vector<int> jobs(maxAbility + 1, 0);
        for (int i = 0; i < difficulty.size(); i++) {
            if (difficulty[i] <= maxAbility)
                jobs[difficulty[i]] = max(jobs[difficulty[i]], profit[i]);
        }
        // Take maxima of prefixes.
        for (int i = 1; i <= maxAbility; i++)
            jobs[i] = max(jobs[i], jobs[i - 1]);

        int netProfit = 0;
        for (auto ability : worker) {
            int maxProfit = jobs[ability];
            netProfit += maxProfit;
        }
        return netProfit;
    }
};