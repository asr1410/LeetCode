class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, ans = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++)
        {
            if (m.find(s[i]) != m.end())
            {
                left = max(m[s[i]] + 1, left);
            }
            m[s[i]] = i;
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};