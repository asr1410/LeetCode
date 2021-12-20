#include <bits/stdc++.h>
using namespace std;
void rotate(vector<int> &nums, int k)
{
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + (k % nums.size()));
    reverse(nums.begin() + (k % nums.size()), nums.end());
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
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 10);
    for (auto &&i : nums)
    {
        cout << i << endl;
    }

    return 0;
}