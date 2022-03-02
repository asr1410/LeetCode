class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int j = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == s[j] and j < s.size())
            {
                j++;
            }
        }
        return j == s.size();
    }
};