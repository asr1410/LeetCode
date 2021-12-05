#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getAverages(vector<int> &v, int k)
    {
        int n = v.size();
        long long int pre[n], suff[n];
        pre[0] = v[0];
        for (int i = 1; i < n; ++i)
        {
            pre[i] = pre[i - 1] + v[i];
        }
        suff[n - 1] = v[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            suff[i] = suff[i + 1] + v[i];
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            if (i - k < 0 || i + k >= n)
            {
                ans.push_back(-1);
            }
            else
            {
                long long int sum = (long long int)((suff[i - k] - suff[i]) + (pre[i + k] - pre[i]) + v[i]);
                sum = sum / (2 * k + 1);
                ans.push_back(sum);
            }
        }
        return ans;
    }
};
// class Solution
// {
// public:
//     vector<int> getAverages(vector<int> &nums, int k)
//     {
//         vector<int> res;
//         int n = nums.size();
//         for (int i = 0; i < n; i++)
//         {
//             if (i - k >= 0 && i + k < n)
//             {
//                 int temp1 = i;
//                 int temp2 = k;
//                 int sum = 0;
//                 do
//                 {
//                     sum += nums[temp1 - temp2] + nums[temp1 + temp2];
//                 } while (temp2-- != 0);
//                 sum -= nums[i];
//                 res.push_back(trunc(sum / (2 * k + 1)));
//             }
//             else
//             {
//                 res.push_back(-1);
//             }
//         }
//         return res;
//     }
// };
int main()
{
    Solution s;
    vector<int> nums = {7, 4, 3, 9, 1, 8, 5, 2, 6};
    int k = 3;
    for (auto &&j : s.getAverages(nums, k))
    {
        cout << j << endl;
    }
    return 0;
}