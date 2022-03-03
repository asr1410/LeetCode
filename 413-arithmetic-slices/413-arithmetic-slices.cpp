class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &n)
    {
        if (n.size() < 3)
            return 0;
        int a = 0, f = 0, s = 1, count, d;
        for (int i = 1; i < n.size(); i++)
        {
            d = n[s] - n[f];
            while (i + 1 < n.size() and d == n[i + 1] - n[i])
                i++, s++;
            count = s - f + 1;
            if (count >= 3)
                a += (count - 2) * (count + 1 - 2) / 2;
            f = s++;
        }
        return a;
    }
};