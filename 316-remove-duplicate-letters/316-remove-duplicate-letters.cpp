class Solution {
public:
    string removeDuplicateLetters(string s)
{
    string ans = "";
    stack<char> st;
    vector<int> mark(26);
    vector<bool> check(26);
    for (auto c : s)
        mark[c - 'a']++;
    for (auto c : s)
    {
        if (check[c - 'a'])
        {
            mark[c - 'a']--;
            continue;
        }
        while (!st.empty() and st.top() > c and mark[st.top() - 'a'])
        {
            check[st.top() - 'a'] = false;
            st.pop();
        }
        st.push(c);
        check[c - 'a'] = true;
        mark[c - 'a']--;
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
};