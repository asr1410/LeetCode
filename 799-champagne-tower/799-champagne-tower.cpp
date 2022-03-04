class Solution
{
public:
    double champagneTower(int poured, int row, int glass)
    {
        vector<double> top(1);
        top[0] = poured;
        for (int i = 0; i < row; i++)
        {
            vector<double> bottom(i + 2);
            for (int j = 0; j <= i; j++)
            {
                double remain = max((top[j] - 1) / 2, 0.0);
                bottom[j] += remain, bottom[j + 1] += remain;
            }
            top = bottom;
        }
        return min(top[glass], 1.0);
    }
};
