#include <bits/stdc++.h>
using namespace std;
string space2underscore(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
            text[i] = '_';
    }
    return text;
}
int main()
{
    string a = "Rotate Array";
    cout << space2underscore(a) << endl;
    return 0;
}