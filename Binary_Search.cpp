#include <bits/stdc++.h>
using namespace std;
int iterativeSearch(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        // if (left == right)
        // {
        //     cout << "left ----> " << left << endl;
        //     cout << "right ----> " << right << endl;
        //     cout << "mid ----> " << mid << endl;
        // }
    }
    return -1;
}
int recursiveSearch(vector<int> &nums, int target, int left, int right)
{
    int mid = left + (right - left) / 2;
    if (left > right)
    {
        return -1;
    }
    else if (nums[mid] == target)
    {
        return mid;
    }
    else if (nums[mid] > target)
    {
        return recursiveSearch(nums, target, left, mid - 1);
    }
    else
    {
        return recursiveSearch(nums, target, mid + 1, right);
    }
}
int recursiveSearch(vector<int> &nums, int target)
{
    return recursiveSearch(nums, target, 0, nums.size() - 1);
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    // for (auto &&i : nums)
    // {
    //     // cout << "the element " << i << " found at index " << iterativeSearch(nums, i) << endl;
    // }
    cout << "the element " << 5 << " found at index " << recursiveSearch(nums, 5) << endl;
    return 0;
}