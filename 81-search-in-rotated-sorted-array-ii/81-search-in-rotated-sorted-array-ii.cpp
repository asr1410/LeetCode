class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        bool present;
        for (auto &&n : nums)
        {
            if (n == target)
            {
                return true;
            }
        }
        return false;
    }
};