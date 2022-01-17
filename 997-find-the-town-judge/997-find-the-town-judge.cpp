class Solution
{
public:
     int findJudge(int n, vector<vector<int>> &trust)
     {
          vector<vector<int>> count(n + 1, vector<int>(2));
          for (auto &&arr : trust)
          {
               count[arr[0]][0]++;
               count[arr[1]][1]++;
          }
          for (int i = 1; i < n + 1; i++)
          {
               if (count[i][1] == n-1 && count[i][0] == 0)
               {
                    return i;
               }
          }
          return -1;
     }
};