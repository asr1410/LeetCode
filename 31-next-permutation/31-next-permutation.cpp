class Solution
{
public: // 3421
     void nextPermutation(vector<int> &nums)
     {
          if (nums.size() < 2)
          {
               return;
          }
          int i, j, k = nums.size();
          for (i = k - 1; i > 0; i--)
          {
               if (nums[i - 1] < nums[i])
                    break;
          }
          if (i == 0)
          {
               reverse(nums.begin(), nums.end());
          }
          else
          {
               // i--;
               for (j = k - 1; j > i-1; j--)
                    if (nums[j] > nums[i-1])
                         break;
               swap(nums[i-1], nums[j]);
               reverse(nums.begin() + i, nums.end());
          }
     }
};