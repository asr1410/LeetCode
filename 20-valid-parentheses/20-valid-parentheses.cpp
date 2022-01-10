class Solution {
public:
    bool isValid(string s)
{
     stack<char> tube;
     for (int i = 0; i < s.length(); i++)
     {
          if (!tube.empty() and ((tube.top() == '(' and s[i] == ')') || (tube.top() == '[' and s[i] == ']') || (tube.top() == '{' and s[i] == '}')))
               tube.pop();
          else
          {
               cout << s[i] << endl;
               tube.push(s[i]);
          }
     }
     return tube.empty();
}
};