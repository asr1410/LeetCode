class Solution
{
public:
    void combination(int ind, int target, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (ind == arr.size()){
            if (target == 0)
                ans.push_back(temp);
        return;
        }
        if(arr[ind]<=target)
        {
            temp.push_back(arr[ind]);
            combination(ind, target - arr[ind], arr, temp, ans);
            temp.pop_back();
        }
        combination(ind + 1, target, arr, temp , ans);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        combination(0, target, candidates, temp, ans);
        return ans;
    }
};