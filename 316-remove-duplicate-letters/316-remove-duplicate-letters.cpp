class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        string res = "";
        vector<int> lastPosition(26);
        vector<bool> check(26);
        for (int i = 0; i < s.size(); i++)
        {
            lastPosition[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (check[s[i] - 'a'])
                continue;
            while (!res.empty() && res.back() > s[i] && lastPosition[res.back() - 'a'] > i)
            {
                check[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            check[s[i] - 'a'] = true;
        }
        return res;
    }
};