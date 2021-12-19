#include <bits/stdc++.h>
using namespace std;
bool Palindrome(string &s)
{
    for (int i = 0, j = s.length() - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}
string firstPalindrome(vector<string> &words)
{
    for (auto &&i : words)
        if (Palindrome(i))
            return i;
    return "";
}
int main()
{
    vector<string> word = {"abc", "car", "ada", "racecar", "cool"};
    cout << firstPalindrome(word) << endl;
    return 0;
}