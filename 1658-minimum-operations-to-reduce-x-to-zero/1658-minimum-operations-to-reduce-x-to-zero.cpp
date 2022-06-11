class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < x) return -1;
        if(sum == x) return nums.size();
        int remain = sum - x, len = 0, left = 0, summ = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            summ += nums[right];
            while (summ > remain)
                summ -= nums[left++];
            if (summ == remain)
                len = max(len, right - left + 1);
        }
        if (len)
            return nums.size() - len;
        return -1;
    }
};