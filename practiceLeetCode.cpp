#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> permute(vector<int> &nums)
{
}
int main()
{
    vector<int> nums = {1, 2, 3};
    for (vector<int> vect1d : permute(nums))
    {
        for (auto &&i : vect1d)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}