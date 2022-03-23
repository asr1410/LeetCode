class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {
        if (startValue > target)
            return startValue - target;
        int count = 0;
        while (startValue != target)
            if (target % 2 == 0 and target > startValue)
                target /= 2,
                    count++;
            else
                target++, count++;
        return count;
    }
};