class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        string res = "";
        vector<int> lastPos(26);
        vector<bool> added(26);
        for (int i = 0; i < s.size(); i++)
        {
            lastPos[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (added[s[i] - 'a'])
                continue;
            while (!res.empty() && res.back() > s[i] && lastPos[res.back() - 'a'] > i)
            {
                added[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            added[s[i] - 'a'] = true;
        }
        return res;
    }
};