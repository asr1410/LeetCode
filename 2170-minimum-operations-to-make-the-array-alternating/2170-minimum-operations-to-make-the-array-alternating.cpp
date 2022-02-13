class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int freq[100001][2] = {}, j, k, res;
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]][1 & i]++;
        for (int i = 1, j = k = res = 0; i < 100001; i++)
        {
            res = max(res, max(freq[i][0] + k, freq[i][1] + j));
            j = max(j, freq[i][0]);
            k = max(k, freq[i][1]);
        }
        return nums.size() - res;
    }
};