class Solution
{
public:
     bool detectCapitalUse(string word)
     {
          int capital = 0;
          for (auto &&alphabet : word)
          {
               if (alphabet >= 65 and alphabet <= 90)
               {
                    capital++;
               }
          }
          if (capital == 0 or capital == word.size())
          {
               return true;
          }
          else if (capital == 1 and word[0] >= 65 and word[0] <= 90)
          {
               return true;
          }
          return false;
     }
};