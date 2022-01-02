class Solution {
public:
    int numPairsDivisibleBy60(vector<int> &time)
{
    int count = 0;
    int mark[60] = {};
    for (int num : time)
    {
        int rem = num % 60;
        if (rem == 0)
            count += mark[rem];
        else
            count += mark[60 - rem];
        mark[rem]++;
    }
    return count;
}
};