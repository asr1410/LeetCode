class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() & 1) return false;

        int balance = 0;
        for (int i = 0; i < s.size(); i++) {
            int val = locked[i] == '0' || s[i] == '(';
            balance += val == 1;
            balance -= val == 0;

            if (balance < 0) return false;
        }
        
        balance = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (locked[i] == '0' || s[i] == ')') {
                balance++;
            } else {
                balance--;
            }
            if (balance < 0) return false;
        }

        return true;
    }
};
