class Solution
{
public:
    void h(int s, vector<int> &c, vector<vector<int>> &r, int k, int n)
    {
        if (n == 0 and c.size() == k)
            r.push_back(c);
        for (int i = s; i <= 9; i++)
        {
            c.push_back(i);
            h(i + 1, c, r, k, n - i);
            c.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> r;
        vector<int> c;
        h(1, c, r, k, n);
        return r;
    }
};