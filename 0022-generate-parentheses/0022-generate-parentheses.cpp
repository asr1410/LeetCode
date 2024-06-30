class Solution {
public:
    void helper(vector<string>& ans, string& temp, int open, int close) {
        if (open == 0 && close == 0) {
            ans.push_back(temp);
        }
        if (open > 0) {
            temp.push_back('(');
            helper(ans, temp, open - 1, close);
            temp.pop_back();
        }
        if (close > open) {
            temp.push_back(')');
            helper(ans, temp, open, close - 1);
            temp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        helper(ans, temp, n, n);
        return ans;
    }
};
