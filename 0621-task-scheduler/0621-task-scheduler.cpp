class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> pcount(26);
        for (auto task : tasks) {
            pcount[task - 'A']++;
        }
        vector<pair<int, int>> temp;
        for (int i = 0; i < 26; i++) {
            if (pcount[i] > 0) {
                temp.push_back({pcount[i], i});
            }
        }
        sort(temp.begin(), temp.end(), greater<pair<int, int>>());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int time = 1;
        for (int i = 0; i < temp.size(); i++) {
            pq.push({i + 1, temp[i].second});
        }
        while (!pq.empty()) {
            if (time >= pq.top().first) {
                auto top = pq.top();
                pq.pop();
                top.first = top.first + n + 1;
                pcount[top.second]--;
                if (pcount[top.second] > 0) {
                    pq.push(top);
                }
            }
            if (pq.empty()) {
                break;
            }
            time++;
        }
        return time;
    }
};