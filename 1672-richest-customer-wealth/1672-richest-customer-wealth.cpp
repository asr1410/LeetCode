class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int rich = 0, cashCount;
        for (auto &&bank : accounts)
        {
            cashCount = 0;
            for (auto &&cash : bank)
                cashCount += cash;
            rich = max(rich, cashCount);
        }
        return rich;
    }
};