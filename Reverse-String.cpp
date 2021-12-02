#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rev(vector<char> &s, int left, int right)
    {
        if (left >= right) // Base Condition
            return;
        swap(s[left++], s[right--]); // makes the problem smaller of same type
        rev(s, left, right);
    }
    void reverseString(vector<char> &s)
    {
        // using STL library
        //  reverse(s.begin(), s.end());
        // for (auto it = s.rbegin(); it != s.rend(); it++)
        //     cout << *it;

        // ITERATIVE APPROACH
        //  for (int i = 0; i < s.size() / 2; i++)
        //  {
        //      swap(s[i], s[s.size() - i - 1]);
        //      // char a = s.at(i);
        //      // s.at(i) = s.at(s.size() - i - 1);
        //      // s.at(s.size() - i - 1) = a;
        //  }

        // RECURSIVE APPROACH
        rev(s, 0, s.size() - 1);
        // ITERATION OF THE VECTOR
        for (auto &&i : s)
        {
            cout << i;
        }
    }
};
int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution r;
    r.reverseString(s);
    return 0;
}