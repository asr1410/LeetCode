class Solution
{
public:
     int minEatingSpeed(vector<int> &piles, int h)
     {
          int lowSpeed = 1, highSpeed = *max_element(piles.begin(), piles.end()), time, speed;
          while (lowSpeed < highSpeed)
          {
               time = 0;
               speed = (lowSpeed + highSpeed) / 2;
               for (auto &&banana : piles)
                    time += ceil(1.0 * banana / speed);
               time <= h ? highSpeed = speed : lowSpeed = speed + 1;
          }
          return highSpeed;
     }
};