#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;
    for (auto &&i : s.targetIndices(nums, target))
    {
        cout << i << endl;
    }
    return 0;
}