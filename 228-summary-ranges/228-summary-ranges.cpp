class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        auto len = nums.size();
        if (!len)
            return ans;
        auto first = nums[0], second = nums[0];
        for (int i = 1; i < len; i++)
            if (second + 1 == nums[i])
                second = nums[i];
            else
            {
                first == second ? ans.push_back(to_string(first)) : ans.push_back(to_string(first) + "->" + to_string(second));
                first = second = nums[i];
            }
        first == second ? ans.push_back(to_string(first)) : ans.push_back(to_string(first) + "->" + to_string(second));
        return ans;
    }
};