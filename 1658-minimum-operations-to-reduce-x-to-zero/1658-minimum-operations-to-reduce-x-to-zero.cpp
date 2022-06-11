class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < x)
            return -1;
        int remain = sum - x;
        int len = 0, left = 0;
        int summ = 0;
        bool check = false;
        for (int i = 0; i < nums.size(); i++)
        {
            summ += nums[i];
            while (summ > remain)
            {
                summ -= nums[left++];
            }
            if (summ == remain)
            {
                len = max(len, i - left + 1);
                check = true;
            }
        }
        if (check)
            return nums.size() - len;
        return -1;
    }
};