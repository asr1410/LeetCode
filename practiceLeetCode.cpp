#include <bits/stdc++.h>
using namespace std;
vector<int> sortedSquare(vector<int> &A)
{
    vector<int> res(A.size());
    int left = 0, right = A.size() - 1;
    while (right)
    {
        if (A[left] * A[left] > A[right] * A[right])
        {
            res[right] = A[left] * A[left];
            A[left] = A[right];
            right--;
        }
        else
        {
            res[right] = A[right] * A[right];
            right--;
        }
    }

    return res;
}
int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    for (auto &&i : sortedSquare(nums))
    {
        cout << i << endl;
    }

    return 0;
}