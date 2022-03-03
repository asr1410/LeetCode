class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;
        int ans = 0, first = 0, second = 1, count, diff;
        for (int i = 1; i < nums.size(); i++)
        {
            diff = nums[second] - nums[first];
            while (i + 1 < nums.size() and diff == nums[i + 1] - nums[i])
                i++, second++;
            count = second - first + 1;
            if (count >= 3)
                ans += (count - 2) * (count + 1 - 2) / 2;
            first = second;
            second++;
        }
        return ans;
    }
};