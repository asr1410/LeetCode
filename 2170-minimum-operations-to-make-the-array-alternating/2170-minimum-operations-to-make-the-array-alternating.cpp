class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int even[100001][1] = {}, odd[1000001][1] = {}, maxeven = 0, maxevenindex = 0, secondmaxeven = 0, maxodd = 0, maxoddindex = 0, secondmaxodd = 0;
        for (int i = 0; i < nums.size(); i++)
            if (i % 2 == 0)
                even[nums[i]][0]++;
            else
                odd[nums[i]][0]++;
        for (int i = 0; i < 100001; i++)
        {
            if (even[i][0] > maxeven)
                secondmaxeven = maxeven, maxeven = even[i][0], maxevenindex = i;
            else if (even[i][0] > secondmaxeven)
                secondmaxeven = even[i][0];
            if (odd[i][0] > maxodd)
                secondmaxodd = maxodd, maxodd = odd[i][0], maxoddindex = i;
            else if (odd[i][0] > secondmaxodd)
                secondmaxodd = odd[i][0];
        }
        if (maxevenindex != maxoddindex)
            return nums.size() - maxeven - maxodd;
        return min(nums.size() - maxeven - secondmaxodd, nums.size() - maxodd - secondmaxeven);
    }
};