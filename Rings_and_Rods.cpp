#include <bits/stdc++.h>
using namespace std;
int countPoints(string rings)
{
    int mark[10][3] = {};
    for (int i = 0; i < rings.length(); i += 2)
    {
        if (rings[i] == 'R')
        {
            mark[rings[i + 1] - '0'][0] = 1;
        }
        if (rings[i] == 'G')
        {
            mark[rings[i + 1] - '0'][1] = 1;
        }
        if (rings[i] == 'B')
        {
            mark[rings[i + 1] - '0'][2] = 1;
        }
    }
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (mark[i][0] == 1 && mark[i][1] == 1 && mark[i][2] == 1)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    string rings = "B0R0G0R9R0B0G0";
    cout << countPoints(rings) << endl;
    return 0;
}