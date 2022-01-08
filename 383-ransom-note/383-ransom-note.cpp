class Solution {
public:
    bool canConstruct(string &ransomNote, string &magazine)
{
     int count[26]{};
     for (int i = 0; i < magazine.size(); i++)
          count[magazine[i] - 'a']++;
     for (int i = 0; i < ransomNote.size(); i++)
          if (!count[ransomNote[i] - 'a']--)
               return false;
     return true;
}
};