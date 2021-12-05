#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char arr[n][3];
    char rec[n][2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
        for (int k = 0; k < 2; k++)
        {
            cin >> rec[i][k];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == rec[i][0] || arr[i][0] == rec[i][1])
        {
            cout << arr[i][0] << endl;
        }
        else if (arr[i][1] == rec[i][0] || arr[i][1] == rec[i][1])
        {
            cout << arr[i][1] << endl;
        }
        else if (arr[i][2] == rec[i][0] || arr[i][2] == rec[i][1])
        {
            cout << arr[i][2] << endl;
        }
    }

    return 0;
}
