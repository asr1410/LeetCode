class Solution {
public:
    void helper(vector<vector<int>> &keypad, string &digits, vector<string> &ans, string &temp, int index) {
        if(digits.size() == temp.size()) {
            ans.push_back(temp);
        } else {
            int digit = digits[index] - '0';
            for(int i = 0; i < keypad[digit].size(); i++) {
                temp.push_back(keypad[digit][i]);
                helper(keypad, digits, ans, temp, index + 1);
                temp.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return {};
        }
        vector<vector<int>> keypad{
            {},
            {},
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };
        string temp;
        vector<string> ans;
        helper(keypad, digits, ans, temp, 0);
        return ans;
    }
};