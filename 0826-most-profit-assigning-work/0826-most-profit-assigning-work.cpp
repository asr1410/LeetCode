class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        int n = difficulty.size(), maxProfit = 0, jobIndex = 0, best = 0;
        
        // Step 1: Combine and sort jobs by difficulty
        for (int i = 0; i < n; ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());
        
        // Step 2: Sort workers
        sort(worker.begin(), worker.end());
        
        // Step 3: Assign jobs to workers
        for (int ability : worker) {
            // Update best profit for current ability
            while (jobIndex < n && ability >= jobs[jobIndex].first) {
                best = max(best, jobs[jobIndex].second);
                ++jobIndex;
            }
            maxProfit += best;
        }
        
        return maxProfit;
    }
};