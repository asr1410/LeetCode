class Solution
{
public:
     bool canJump(vector<int> &nums)
     {
          int length = nums.size();
          if (length == 1)
               return true;
          else if (nums[0] == 0)
               return false;
          int maxReach = 0;
          for (int i = 0; i < length; i++)
          {
               if (maxReach < i)
                    return false;
               if (i + nums[i] > maxReach)
                    maxReach = i + nums[i];
          }
          return true;
     }
};