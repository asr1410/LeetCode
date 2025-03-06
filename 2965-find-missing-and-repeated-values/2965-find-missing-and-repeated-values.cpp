class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> mark(n * n + 1, 0);
        for(const auto& row : grid) {
            for(const int& val : row) {
                mark[val]++;
            }
        }
        n *= n;
        n++;
        int a, b;
        for(int i = 1; i < n; i++) {
            if(mark[i] == 0) {
                a = i;
            }
            if(mark[i] == 2) {
                b = i;
            }
        }
        return {b, a};
    }
};