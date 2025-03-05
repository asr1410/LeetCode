class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1, prev = 0;
        for(int i = 1; i < n; i++) {
            prev += 4;
            ans += prev;
        }
        return ans;
    }
};