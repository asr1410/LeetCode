class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<char> v;
        for(char c : s) {
            if(v.empty() == false and v.back() == '(' and c == ')') {
                v.pop_back();
            } else {
                v.push_back(c);
            }
        }
        return v.size();
    }
};