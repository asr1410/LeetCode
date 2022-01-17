class Solution {
public:
    bool wordPattern(string pattern, string s)
{
     int cnt = 0;
     vector<string> temp;
     for (int i = 0; i < s.size(); i++)
     {
          string str;
          while (s[i] != ' ' && i < s.size())
          {
               str.push_back(s[i]);
               i++;
          }
          cnt++;
          temp.push_back(str);
     }
     if (cnt != pattern.size())
     {
          return false;
     }
     unordered_map<string, char> map;
     set<char> count;
     for (int i = 0; i < pattern.size(); i++)
     {
          if (map.find(temp[i]) == map.end() && count.find(pattern[i]) == count.end())
          {
               count.insert(pattern[i]);
               map.emplace(temp[i], pattern[i]);
          }
          else if (map[temp[i]] != pattern[i])
          {
               return false;
          }
     }
     return true;
}
};