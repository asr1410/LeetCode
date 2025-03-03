class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> small;
        vector<int> equal;
        vector<int> greater;
        for (auto &&num : nums)
        {
            if (num < pivot)
            {
                small.push_back(num);
            }
            else if (num == pivot)
            {
                equal.push_back(num);
            }
            else
            {
                greater.push_back(num);
            }
        }
        for (auto &&num : equal)
        {
            small.push_back(num);
        }
        for (auto &&num : greater)
        {
            small.push_back(num);
        }
        return small;
    }
};