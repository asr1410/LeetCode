class Solution {
public:
    int minMoves(int target, int maxDoubles)
{
     int jump = 0;
     while (target && maxDoubles)
     {
          if (target % 2)
               target--;
          else
          {
               target /= 2;
               maxDoubles--;
          }
          jump++;
     }
     return jump + target - 1;
}
};