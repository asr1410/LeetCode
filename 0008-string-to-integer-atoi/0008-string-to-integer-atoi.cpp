class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        int num = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';
            if (num > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return num * sign;
    }
};