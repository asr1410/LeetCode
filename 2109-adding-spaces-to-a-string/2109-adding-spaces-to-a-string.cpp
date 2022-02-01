class Solution
{
public:
     string addSpaces(string s, vector<int> &spaces)
     {
          string ans;
          int j = 0;
          for (auto &&i : spaces)
          {
               while (j < i)
               {
                    ans.push_back(s[j++]);
               }
               ans.push_back(' ');
          }
         while (j < s.size())
          {
               ans.push_back(s[j++]);
          }
          return ans;
     }
};