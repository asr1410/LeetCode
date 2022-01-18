class Solution
{
public:
     bool canPlaceFlowers(vector<int> &flowerbed, int n)
     {
          if (n == 0)
          {
               return true;
          }
          else if (flowerbed.size() == 1 and flowerbed[0] == 0 and n == 1)
          {
               return true;
          }
          for (int i = 0; i < flowerbed.size(); i++)
          {
               if (i == 0 and flowerbed[i] == 0 and flowerbed[i + 1] == 0)
               {
                    flowerbed[i] = 1;
                    n--;
               }
               else if (i == flowerbed.size() - 1 and flowerbed[i] == 0 and flowerbed[i - 1] == 0)
               {
                    flowerbed[i] = 1;
                    n--;
               }
               else if (i > 0 and i < flowerbed.size() - 1 and flowerbed[i] == 0 and flowerbed[i + 1] == 0 and flowerbed[i - 1] == 0)
               {
                    flowerbed[i] = 1;
                    n--;
               }
          }
          return n <= 0;
     }
};