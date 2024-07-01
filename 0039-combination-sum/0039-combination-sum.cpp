class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> &cand, vector<int> &temp, int &tsum, int &csum, int index) {
        if(csum >= tsum) {
            if(csum == tsum) {
                ans.push_back(temp);
            }
        } else {
            for(int i = index; i < cand.size(); i++) {
                csum += cand[i];
                temp.push_back(cand[i]);
                helper(ans, cand, temp, tsum, csum, i);
                temp.pop_back();
                csum -= cand[i];
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int tsum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int csum = 0;
        helper(ans, cand, temp, tsum, csum, 0);
        return ans;
    }
};