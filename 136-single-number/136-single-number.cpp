class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        return accumulate(nums.cbegin(), nums.cend(), 0, bit_xor<int>());
    }
};