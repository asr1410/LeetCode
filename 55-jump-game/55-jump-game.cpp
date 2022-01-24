class Solution
{
public:
     bool canJump(vector<int> &nums)
     {
          int jump = nums.size() - 1;
          for (int i = jump - 1; i >= 0; i--)
          {
               if (nums[i] + i >= jump)
               {
                    jump = i;
               }
          }
          return jump == 0;
     }
};