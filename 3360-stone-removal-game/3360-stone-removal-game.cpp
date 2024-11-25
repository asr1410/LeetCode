class Solution {
public:
    bool canAliceWin(int n) {
        int rem = 10;
        int turn = 1;
        while(n - rem >= 0) {
            n -= rem;
            rem -= 1;
            turn ^= 1;
        }
        return turn == 0;
    }
};