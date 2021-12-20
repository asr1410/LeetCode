#include <bits/stdc++.h>
using namespace std;
vector<int> sortedSquare(vector<int> &nums)
{
    vector<int> ans(nums.size());
    int left = 0, right = nums.size() - 1;
    int largest = nums.size() - 1;
    while (left < right)
    {
        if (nums[left] * nums[left] > nums[right] * nums[right])
        {
            ans[largest--] = nums[left] * nums[left++];
        }
        else
        {
            ans[largest--] = nums[right] * nums[right--];
        }
    }
    ans[largest] = nums[right] * nums[left];
    return ans;
}
int main()
{
    vector<int> nums = {-7, -3, 2, 3, 11};
    for (auto &&i : sortedSquare(nums))
    {
        cout << i << endl;
    }

    return 0;
}