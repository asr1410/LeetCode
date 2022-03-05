class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        auto mx = max_element(nums.begin(), nums.end());
        int len = *mx + 1, ans = 0;
        vector<int> mark(len);
        for (auto &&num : nums)
            mark[num] += num;
        int take = 0, skip = 0;
        for (int i = 0; i < len; i++)
        {
            int takei = skip + mark[i], skipi = max(skip, take);
            take = takei, skip = skipi;
        }
        return max(take, skip);
    }
};