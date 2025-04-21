class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        // 0 1 -2 2
        // 1 2 -1 3
        // 2 3 0 4
        // 3 4 1 5 
        int n = diff.size(), mn = 0, mx = 0;
        for(int i = 0, prev = 0; i < n; i++) {
            prev += diff[i];
            mn = min(mn, prev);
            mx = max(mx, prev);
        }
        int up = mx + (lower - mn);
        return max(0, upper - up + 1);
    }
};