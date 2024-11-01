class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        for(char c : s) {
            if(ans.size() > 1) {
                if(ans[ans.size() - 1] != c or ans[ans.size() - 2] != c) {
                    ans.push_back(c);
                }
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};