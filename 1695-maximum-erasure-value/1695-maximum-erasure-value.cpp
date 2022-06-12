class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int score = 0, left = 0, temp = 0;
        unordered_map<int, pair<bool, int>> mark;
        for (int right = 0; right < nums.size(); right++)
        {
            if (mark.find(nums[right]) == mark.end())
                mark.insert({nums[right], make_pair(true, right)}), temp += nums[right];
            else
            {
                while (left <= mark[nums[right]].second)
                    temp -= nums[left++];
                mark[nums[right]].second = right, temp += nums[right];
            }
            score = max(score, temp);
        }
        return score;
    }
};