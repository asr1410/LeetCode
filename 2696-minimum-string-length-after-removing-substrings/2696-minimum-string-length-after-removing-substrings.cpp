class Solution {
public:
    int minLength(string s) {
        vector<char> st;
        for(char c : s) {
            if(st.empty() == true) {
                st.push_back(c);
            } else if((st.back() == 'A' and c == 'B') or (st.back() == 'C' and c == 'D')) {
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        return st.size();
    }
};