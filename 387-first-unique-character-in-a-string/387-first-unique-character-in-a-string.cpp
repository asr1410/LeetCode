class Solution {
public:
    int firstUniqChar(string &s)
{
     int count[26]{};
     for (int i = 0; i < s.size(); i++)
     {
          count[s[i] - 'a']++;
     }
     for (int i = 0; i < s.size(); i++)
     {
          if (count[s[i] - 'a'] == 1)
               return i;
     }
     return -1;
}
};