class Solution {
public:
    bool possible(int m, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> mset(workers.end() - m, workers.end());  // Take strongest 'm' workers
        for (int i = m - 1; i >= 0; i--) {  // Traverse from hardest to easiest task
            auto it = mset.lower_bound(tasks[i]);
            if (it == mset.end()) {
                if (pills == 0) return false;
                // Try using a pill
                it = mset.lower_bound(tasks[i] - strength);
                if (it == mset.end()) return false;
                pills--;
            }
            if (*it < tasks[i]) return false;
            mset.erase(it);
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(workers.begin(), workers.end());
        sort(tasks.begin(), tasks.end());
        int l = 0, r = min((int)tasks.size(), (int)workers.size()), ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (possible(m, tasks, workers, pills, strength)) {
                ans = m + 1;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};
