class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        char prev = '(';
        int res = 0, depth = 0;
        for (auto &&c : s)
        {
            if (c == '(')
                depth++;
            else
            {
                depth--;
                if (prev == '(')
                    res += pow(2, depth);
            }
            prev = c;
        }
        return res;
    }
};