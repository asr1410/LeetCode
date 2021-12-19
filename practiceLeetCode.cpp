#include <bits/stdc++.h>
using namespace std;
void recurPermute(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, bool freq)
{
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