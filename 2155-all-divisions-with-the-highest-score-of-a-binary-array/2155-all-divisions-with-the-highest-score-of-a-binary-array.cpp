class Solution
{
public:
    vector<int> maxScoreIndices(vector<int> &nums)
    {
        int ones = accumulate(nums.begin(), nums.end(), 0), zeros = 0, score = 0;
        vector<int> ans;
        for (int i = 0; i <= nums.size(); i++)
        {
            if (ones + zeros > score)
            {
                score = ones + zeros;
                ans.clear();
            }
            if (ones + zeros == score)
            {
                ans.push_back(i);
            }
            if (i < nums.size())
            {
                ones = ones - nums[i];
                zeros = zeros + (nums[i] == 0);
            }
        }
        return ans;
    }
};