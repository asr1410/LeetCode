//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        int space = n - 1, star = 1;
        for (int i = 0; i < n; i++) {
            int tspace = space, tstar = star;
            while (tspace--)
                cout << " ";
            while (tstar--)
                cout << "*";
            cout << endl;
            space--, star += 2;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends