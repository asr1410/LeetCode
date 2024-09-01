class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& og, int m, int n) {
        if(og.size() != m * n) {
            return {};
        }
        vector<vector<int>> ans(m, vector<int> (n, 0));
        for(int i = 0; i < og.size(); i++) {
            int row = i / n;
            int col = i % n;
            ans[row][col] = og[i];
        }
        return ans;
    }
};