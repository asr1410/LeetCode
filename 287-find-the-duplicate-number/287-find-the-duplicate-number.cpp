class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        vector<bool> mark(100001);
        for (int i = 0; i < nums.size(); i++)
        {
            if (mark[nums[i]])
                return nums[i];
            mark[nums[i]] = true;
        }
        return -1;
    }
};