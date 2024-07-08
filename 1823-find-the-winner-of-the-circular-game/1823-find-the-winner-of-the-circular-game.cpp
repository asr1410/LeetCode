class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0;
        for (int i = 2; i <= n; ++i) {
            winner = (winner + k) % i;
        }
        return winner + 1; // +1 to convert zero-based index to one-based index
    }
};