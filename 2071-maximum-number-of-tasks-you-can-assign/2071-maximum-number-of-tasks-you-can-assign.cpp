class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& ws, int pills, int strength) {
        int l = 0, r = min(tasks.size(), ws.size());
        sort(begin(tasks), end(tasks));
        sort(begin(ws), end(ws));
        while (l < r) {
            int m = (l + r + 1) / 2, need = 0;
            multiset<int> ms(end(ws) - m, end(ws));
            for (int i = m - 1; i >= 0; --i) {
                auto it = prev(end(ms));
                if (*it < tasks[i]) {
                    it = ms.lower_bound(tasks[i] - strength);
                    if (it == end(ms) || ++need > pills)
                        break;
                }
                ms.erase(it);
            }
            if (ms.empty())
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};