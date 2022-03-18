class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        stack<int> st;
        int result = 0;
        for (auto &&c : s)
        {
            if (c == '(')
            {
                st.push(result);
                result = 0;
            }
            else
            {
                result = st.top() + max(result * 2, 1);
                st.pop();
            }
        }
        return result;
    }
};