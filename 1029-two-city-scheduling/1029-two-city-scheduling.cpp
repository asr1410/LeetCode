class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        sort(costs.begin(), costs.end(), [](const auto &a, const auto &b)
             { return a[1] - a[0] > b[1] - b[0]; });
        int n = costs.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += i >= n / 2 ? costs[i][1] : costs[i][0];
        }
        return ans;
    }
};