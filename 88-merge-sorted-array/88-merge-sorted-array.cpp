class Solution
{
public:
    void merge(vector<int> &a, int m, vector<int> &b, int n)
    {
        while (n)
        {
            a[m + n] = (m > 0 && a[m - 1] > b[n - 1]) ? a[--m] : b[--n];
        }
    }
};