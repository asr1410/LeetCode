class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < x)
            return -1;
        if (sum == x)
            return nums.size();
        int remain = sum - x, maxLen = 0, left = 0, tSum = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            tSum += nums[right];
            while (tSum > remain)
                tSum -= nums[left++];
            if (tSum == remain)
                maxLen = max(maxLen, right - left + 1);
        }
        if (maxLen)
            return nums.size() - maxLen;
        return -1;
    }
};