class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bc2 = __builtin_popcount(num2);
        int result = 0;

        for (int i = 31; i >= 0 && bc2 > 0; --i) {
            if (num1 & (1 << i)) {
                result |= (1 << i);
                --bc2;
            }
        }

        for (int i = 0; i < 32 && bc2 > 0; ++i) {
            if (!(result & (1 << i))) {
                result |= (1 << i);
                --bc2;
            }
        }

        return result;
    }
};
