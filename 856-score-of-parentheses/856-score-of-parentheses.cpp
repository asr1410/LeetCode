class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int result = 0;
        stack<int> st;
        for (auto &&c : s)
        {
            if (c == '(')
            {
                st.push(result);
                result = 0;
            }
            else
            {
                result = st.top() + max(2 * result, 1);
                st.pop();
            }
        }
        return result;
    }
};