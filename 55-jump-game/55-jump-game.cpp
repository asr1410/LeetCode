class Solution
{
public:
     bool canJump(vector<int> &nums)
     {
          if (nums.size() == 1)
          {
               return true;
          }
          if (nums[0] == 0)
          {
               return false;
          }
          int jump = 0;
          for (int i = 0; i < nums.size(); i++)
          {
               if (nums[i] + i <= i && jump <= i)
               {
                    break;
               }
               jump = max(jump, nums[i] + i);
          }
          return jump >= nums.size() - 1;
     }
};