class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        sort(strength.begin(), strength.end());
        int res = INT_MAX, size = strength.size(), prev = 0, energy = 1;
        do {
            int time = 0;
            int x = 1;
            for (int i = 0; i < size; i++) {
                int s = strength[i];
                time += (s + x - 1 ) / x;
                x += k;
            }
            res = min(res, time);
        } while (next_permutation(strength.begin(), strength.end()));

        return res;
    }
};