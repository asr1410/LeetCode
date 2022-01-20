class Solution
{
public:
     int minEatingSpeed(vector<int> &piles, int h)
     {
          int left = 1, right = 0;
          for (auto &&banana : piles)
          {
               right = max(right, banana);
          }
          while (left < right)
          {
               int time = 0;
               int speed = (left + right) / 2;
               for (auto &&banana : piles)
               {
                    time += ceil(1.0 * banana / speed);
               }
               if (time <= h)
                    right = speed;
               else
                    left = speed + 1;
          }
          return right;
     }
};