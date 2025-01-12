class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() & 1) return false;

        int open = 0, balance = 0;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0' || s[i] == '(') {
                open++;
                balance++;
            } else {
                balance--;
            }
            if (balance < 0) return false;
        }

        open = 0, balance = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (locked[i] == '0' || s[i] == ')') {
                open++;
                balance++;
            } else {
                balance--;
            }
            if (balance < 0) return false;
        }

        return true;
    }
};
