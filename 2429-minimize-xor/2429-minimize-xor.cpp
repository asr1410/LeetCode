class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bc1 = __builtin_popcount(num1);
        int bc2 = __builtin_popcount(num2);

        if(bc1 == bc2) {
            return num1;
        } else if(bc2 > bc1) {
            int ans = num1;
            int rem = bc2 - bc1;
            int idx = 0;
            while(rem) {
                if(!((num1 >> idx) & 1)) {
                    ans |= (1 << idx);
                    rem--;
                }
                idx++;
            }
            return ans;
        }
        int idx = 30;
        int ans = 0;
        while(bc2) {
            if((num1 >> idx) & 1) {
                ans |= (1 << idx);
                bc2--;
            }
            idx--;
        }
        return ans;
    }
};
