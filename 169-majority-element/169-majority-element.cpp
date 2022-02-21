class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = nums[0], mx = 0, count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
            {
                count++;
                if (count > mx)
                {
                    mx = count;
                    ans = nums[i];
                }
            }
            else
                count = 1;
        }
        return ans;
    }
};