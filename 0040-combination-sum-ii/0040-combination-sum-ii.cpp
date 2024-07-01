class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& temp, int index) {
        if(!target)
            res.push_back(temp);
        for(int i = index; i < candidates.size(); ++i) {
            if(i != index and candidates[i] == candidates[i - 1]) continue;
            else if(candidates[i] > target) break;
            temp.push_back(candidates[i]);
            helper(candidates, target - candidates[i], res, temp, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, res, temp, 0);
        return res;
    }
};