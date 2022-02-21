class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int mx = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == mx)
                count++;
            else
                if(count > 1) count--;
            else
                mx = nums[i], count = 1;
        }
        return mx;
    }
};