class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> mark;
        for (auto &&num : nums)
            mark[num]++;
        for (auto &&num : mark)
            if (num.second == 1)
                return num.first;
        return -1;
    }
};