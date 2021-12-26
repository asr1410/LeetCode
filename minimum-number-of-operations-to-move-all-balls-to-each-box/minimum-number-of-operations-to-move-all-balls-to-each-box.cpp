class Solution {
public:
    vector<int> minOperations(string s) {
        vector<int> result;
    for (int i = 0; i < s.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            else if (s[j] == '1')
            {
                if (j > i)
                {
                    count += j - i;
                }
                else
                {
                    count += i - j;
                }
            }
        }
        result.push_back(count);
    }
    return result;
    }
};