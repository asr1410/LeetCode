//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
	
	void printTriangle(int n) {
	    int space = 0, star = 2 * n - 1;
	    while(n--) {
	        int tstar = star, tspace = space;
	        while (tspace--)
	            cout << " ";
	        while (tstar--)
	            cout << "*";
	        cout << endl;
            space++, star -= 2;
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