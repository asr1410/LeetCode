#include <bits/stdc++.h>
using namespace std;
vector<int> maxSequence(vector<int> &nums, int k)
{
    vector<int> mark(nums.size(), 0);
    vector<int> result;
    for (int i = 0; i < k; i++)
    {
        int Cmax = INT_MIN;
        int index = -1;
        for (int j = 0; j < nums.size(); j++)
        {
            if (mark[j] == 1)
            {
                continue;
            }
            if (nums[j] > Cmax)
            {
                Cmax = nums[j];
                index = j;
            }
        }
        mark[index] = 1;
    }
    for (int i = 0; i < mark.size(); i++)
    {
        if (mark[i] == 1)
        {
            result.push_back(nums[i]);
            // cout << nums[i] << endl;
        }
    }
    return result;
}
int main()
{
    vector<int> nums = {18, 3, 19, -8, 30, 22, -35, 11, 16, 18, -21, 32, -7, -6, 38, 25, -21, -1, 26, -8, -37, -39, -34, 6, -36, -3, 26, -32, 22, -20, 35, -35, -30, -8, 11, 7, -23, -9, -22, 1, 33, -6, 12, 2, 27, -27, 28, -12, 21, 12, 16, 21, 33};
    maxSequence(nums, 50);
    return 0;
}