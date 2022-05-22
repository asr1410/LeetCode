class Solution
{
public:
    int ans = 0;
    bool isPalindrome(string str)
    {
        int l = 0;
        int h = str.size() - 1;
        while (h > l)
            if (str[l++] != str[h--])
                return 0;
        return 1;
    }
    void printSubstrings(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            string subStr;
            for (int j = i; j < str.length(); j++)
            {
                subStr += str[j];
                if (isPalindrome(subStr))
                    ans++;
            }
        }
    }
    int countSubstrings(string s)
    {
        printSubstrings(s);
        return ans;
    }
};