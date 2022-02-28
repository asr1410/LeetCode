class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        vector<int> temp;
        int n = nums.size();
        if (!n)
            return ans;
        int first = nums[0];
        temp.push_back(first);
        for (int i = 1; i < n; i++)
        {
            if (first + 1 == nums[i])
            {
                first = nums[i];
                temp.push_back(first);
            }
            else
            {
                first = nums[i];
                if (temp.size() == 1)
                {
                    ans.push_back(to_string(temp[0]));
                }
                else
                {
                    ans.push_back(to_string(temp.front()) + "->" + to_string(temp.back()));
                }
                temp.clear();
                temp.push_back(first);
            }
        }
        if(temp.size())
            {
                if (temp.size() == 1)
                {
                    ans.push_back(to_string(temp[0]));
                }
                else
                {
                    ans.push_back(to_string(temp.front()) + "->" + to_string(temp.back()));
                }
            }
        return ans;
    }
};