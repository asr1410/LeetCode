class Solution
{
public:
     int minEatingSpeed(vector<int> &piles, int h)
     {
          int lowSpeed = 1, highSpeed = *max_element(piles.begin(), piles.end());
          while (lowSpeed < highSpeed)
          {
               int time = 0;
               int speed = (lowSpeed + highSpeed) / 2;
               for (auto &&banana : piles)
               {
                    time += ceil(1.0*banana / speed);
               }
               if (time <= h)
                    highSpeed = speed;
               else
                    lowSpeed = speed + 1;
          }
          return highSpeed;
     }
};