class Solution
{
public:
    vector<int> maxScoreIndices(vector<int> &nums)
    {
        int n = nums.size();
        int prefix[n], suffix[n];
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                prefix[i] = (nums[i] == 0);
            }
            else
            {
                prefix[i] = prefix[i - 1] + (nums[i] == 0);
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                suffix[i] = (nums[i] == 1);
            }
            else
            {
                suffix[i] = suffix[i + 1] + (nums[i] == 1);
            }
        }
        unordered_map<int, vector<int>> ans;
        int mx = 0;
        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
            {
                ans[suffix[i]].push_back(i);
                mx = max(mx, suffix[i]);
            }
            else if (i == n)
            {
                ans[prefix[i - 1]].push_back(i);
                mx = max(mx, prefix[i - 1]);
            }
            else
            {
                ans[prefix[i - 1] + suffix[i]].push_back(i);
                mx = max(mx, prefix[i - 1] + suffix[i]);
            }
        }
        return ans[mx];
    }
};