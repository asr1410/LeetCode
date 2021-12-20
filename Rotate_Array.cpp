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

    // reverse(nums.begin(), nums.end());
    // reverse(nums.begin(), nums.begin() + (k % nums.size()));
    // reverse(nums.begin() + (k % nums.size()), nums.end());

    // if (nums.size() < k)
    // {
    //     k %= nums.size();
    // }
    // vector<int> temp(k);
    // while (k--)
    // {
    //     temp[k] = nums.back();
    //     nums.pop_back();
    // }
    // nums.insert(nums.begin(), temp.begin(), temp.end());

    // while (k--)
    // {
    //     int temp = nums.back();
    //     nums.pop_back();
    //     nums.insert(nums.begin(), temp);
    // }
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