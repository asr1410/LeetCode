class Solution
{
public:
     void dfs(vector<int> &result, int i, int j, int low, int high)
     {
          if (i >= low and i <= high)
          {
               result.push_back(i);
          }
          if (i > high or j > 9)
          {
               return;
          }
          i = i * 10 + j;
          j++;
          dfs(result, i, j, low, high);
     }
     vector<int> sequentialDigits(int low, int high)
     {
          vector<int> result;
          for (int j = 1; j < 10; j++)
          {
               dfs(result, 0, j, low, high);
          }
          sort(result.begin(), result.end());
          return result;
     }
};