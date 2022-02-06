class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (auto &&num : nums)
        {
            if (i < 2 or num > nums[i - 2])
            {
                nums[i++] = num;
            }
        }
        return i;
    }
};