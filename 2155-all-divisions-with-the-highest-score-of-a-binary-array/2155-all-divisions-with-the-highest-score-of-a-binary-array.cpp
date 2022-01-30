class Solution
{
public:
    vector<int> maxScoreIndices(vector<int> &nums)
    {
        int score = accumulate(begin(nums), end(nums), 0), max_score = score;
        vector<int> res{0};
        for (int i = 0; i < nums.size(); ++i)
        {
            score += (nums[i] == 0) - nums[i];
            if (score > max_score)
            {
                max_score = score;
                res.clear();
            }
            if (score == max_score)
                res.push_back(i + 1);
        }
        return res;
    }
};