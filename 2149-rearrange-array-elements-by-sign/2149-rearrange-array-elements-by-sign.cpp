class Solution
{
public:
     vector<int> rearrangeArray(vector<int> &nums)
     {
          vector<int> pos(nums.size() / 2), neg(nums.size() / 2);
          int l = 0, m = 0;
          for (int i = 0; i < nums.size(); i++)
               nums[i] < 0 ? neg[l++] = nums[i] : pos[m++] = nums[i];
          for (int i = 0; i < nums.size() / 2; i++)
               nums[2 * i] = pos[i], nums[2 * i + 1] = neg[i];
          return nums;
     }
};