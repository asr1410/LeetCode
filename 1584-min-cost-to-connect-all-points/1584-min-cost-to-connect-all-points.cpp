class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int ans = 0, i = 0, size = points.size(), connect = 0;
        vector<bool> mark(size);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        while (++connect < size)
        {
            mark[i] = true;
            for (int j = 0; j < size; j++)
                if (!mark[j])
                    pq.push(make_pair(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), j));
            while (mark[pq.top().second])
                pq.pop();
            ans += pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};