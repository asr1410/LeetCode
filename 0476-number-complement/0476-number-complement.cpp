class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = 1;
        while (mask <= num) {
            mask <<= 1;
        }

        mask -= 1;

        return num ^ mask;
    }
};
