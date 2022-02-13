class Solution
{

public:
    int minimumOperations(vector<int> &nums)
    {
        int freq[100005][2] = {};
        int n = nums.size(), i, j, k, ans = 0;
        for (i = 0; i < n; i++)
        {
            freq[nums[i]][i & 1]++;
        }
        for (i = 1, j = k = 0; i <= 100000; i++)
        {
            ans = max(ans, max(freq[i][0] + k, freq[i][1] + j));
            j = max(j, freq[i][0]);
            k = max(k, freq[i][1]);
        }
        return n - ans;
    }
};