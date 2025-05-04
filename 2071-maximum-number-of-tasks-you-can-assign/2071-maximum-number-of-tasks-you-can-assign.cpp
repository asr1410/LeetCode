class Solution {
public:
    bool possible(int m, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> workerSet(workers.end() - m, workers.end());
        for (int i = m - 1; i >= 0; i--) {
            auto it = workerSet.lower_bound(tasks[i]);
            if (it == workerSet.end()) {
                if (pills == 0) return false;
                it = workerSet.lower_bound(tasks[i] - strength);
                if (it == workerSet.end()) return false;
                pills--;
            }
            workerSet.erase(it);
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int left = 0, right = min(tasks.size(), workers.size());
        int ans = 0;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (possible(mid, tasks, workers, pills, strength)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};