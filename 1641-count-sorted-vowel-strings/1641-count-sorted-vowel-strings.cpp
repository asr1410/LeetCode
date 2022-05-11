class Solution
{
public:
    int countVowelStrings(int n)
    {
        vector<int> v(5, 1);
        for (int i = 2; i <= n; i++)
        {
            for (int i = 3; i >= 0; i--)
            {
                v[i] += v[i + 1];
            }
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};