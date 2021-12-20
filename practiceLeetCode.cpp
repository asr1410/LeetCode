#include <bits/stdc++.h>
using namespace std;
void rotate(vector<int> &nums, int k)
{
    for (int n = nums.size(), start = 0; k = k % n; n = n - k, start = start + k)
    {
        cout << "outside" << endl;
        cout << n << endl;
        cout << start << endl;
        cout << k << endl;
        for (int i = 0; i < k; i++)
        {
            cout << "inside" << endl;
            cout << "1st  " << start + i << endl;
            cout << "2nd  " << start + n - k + i << endl;
            swap(nums[start + i], nums[start + n - k + i]);
            for (auto &&i : nums)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    rotate(nums, 11);
    for (auto &&i : nums)
    {
        // cout << i << endl;
    }

    return 0;
}