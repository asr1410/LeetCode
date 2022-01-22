class Solution
{
public:
     int numberOfArrays(vector<int> &A, int lower, int upper)
     {
          long total = 0, minimum = 0, maximum = 0;
          for (int num : A)
          {
               total += num;
               maximum = max(maximum, total);
               minimum = min(minimum, total);
          }
          return max(0L, minimum - maximum + upper - lower + 1);
     }
};