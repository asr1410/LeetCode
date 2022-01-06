class Solution
{
public:
     bool searchMatrix(vector<vector<int>> &matrix, int target)
     {
          int row = 0;
          for (int i = 0; i < matrix.size(); i++)
          {
               if (matrix[i][0] <= target && matrix[i][matrix[0].size() - 1] >= target)
               {
                    for (int j = 0; j < matrix[i].size(); j++)
                    {
                         if (matrix[i][j] == target)
                              return true;
                    }
                    return false;
               }
          }
         return false;
     }
};