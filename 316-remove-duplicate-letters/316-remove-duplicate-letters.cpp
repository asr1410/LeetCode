class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        string ans = "";
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
            while (!ans.empty() && ans.back() > s[i] && lastPosition[ans.back() - 'a'] > i)
            {
                check[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            check[s[i] - 'a'] = true;
        }
        return ans;
    }
};