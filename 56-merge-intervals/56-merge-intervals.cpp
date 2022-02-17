class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int first = intervals[0][0], second = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (second >= intervals[i][0])
            {
                second = max(second, intervals[i][1]);
            }
            else
            {
                ans.push_back({first, second});
                first = intervals[i][0], second = intervals[i][1];
            }
        }
        if (ans.empty())
        {
            ans.push_back({first, second});
        }
        else if (ans.back().back() < first)
        {
            ans.push_back({first, second});
        }
        return ans;
    }
};