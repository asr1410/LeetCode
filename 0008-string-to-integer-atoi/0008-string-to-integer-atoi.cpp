class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0, i = 0, n = s.size(), sign = 1, scount = 0;

        for (; i < n; i++) {
            if (s[i] != ' ') {
                break;
            }
        }

        for (; i < n; i++) {
            if (s[i] != '-' && s[i] != '+') {
                break;
            } else if (s[i] == '-') {
                sign = -1;
                scount++;
            } else {
                sign = 1;
                scount++;
            }
        }

        for (; i < n; i++) {
            if (s[i] != '0') {
                break;
            }
        }

        if (scount > 1) {
            return 0;
        }

        for (; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + (s[i] - '0');
                if (sign * ans > INT_MAX) {
                    return INT_MAX;
                } else if (sign * ans < INT_MIN) {
                    return INT_MIN;
                }
            } else {
                break;
            }
        }

        ans = ans * sign;
        return static_cast<int>(ans);
    }
};