class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        if (n == k)
            return "0";
        stack<char> temp;
        for (auto &&c : num)
        {
            while (!temp.empty() and k > 0 and temp.top() > c)
            {
                temp.pop(), k--;
            }
            if (!temp.empty() or c != '0')
            {
                temp.push(c);
            }
        }
        while (!temp.empty() and k--)
        {
            temp.pop();
        }
        if (temp.empty())
        {
            return "0";
        }
        while (!temp.empty())
        {
            num[n - 1] = temp.top();
            temp.pop();
            n--;
        }
        return num.substr(n);
    }
};