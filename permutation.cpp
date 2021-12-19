#include <bits/stdc++.h>
using namespace std;
void recurPermute(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, bool *freq)
{
    if (ds.size() == nums.size())
        return ans.push_back(ds);
    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            freq[i] = true;
            ds.push_back(nums[i]);
            recurPermute(nums, ds, ans, freq);
            ds.pop_back();
            freq[i] = false;
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    bool freq[nums.size() - 1];
    recurPermute(nums, ds, ans, freq);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    for (vector<int> vec : permute(nums))
    {
        for (auto &&i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}