class Solution
{
private:
    long helper(string &s, int idx)
    {
        if (!idx)
            return s[idx] - 'A' + 1;
        return 26 * helper(s, idx - 1) + s[idx] - 'A' + 1;
    }

public:
    int titleToNumber(string columnTitle)
    {
        return helper(columnTitle, columnTitle.size() - 1);
    }
};