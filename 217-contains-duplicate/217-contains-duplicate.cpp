class Solution
{
public:
     bool containsDuplicate(vector<int> &nums)
     {
          set<int> mark;
          for (auto &&i : nums)
          {
               if (mark.find(i) == mark.end())
                    mark.insert(i);
               else
                    return true;
          }
          return false;
     }
};