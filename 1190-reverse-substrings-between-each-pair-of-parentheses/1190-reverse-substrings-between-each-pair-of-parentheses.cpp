class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string temp;
        for(auto c:s) {
            if(c == ')') {
                temp = "";
                while(st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                for(auto t:temp) {
                    st.push(t);
                }
            } else {
                st.push(c);
            }
        }
        temp = "";
        while(st.empty() == false) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};