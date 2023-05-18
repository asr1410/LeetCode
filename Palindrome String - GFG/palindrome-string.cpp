//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    bool rev(string& s, int left) {
        int right = s.length() - 1 - left;
        
        if (left >= right)
            return true;
        
        if (s[left] != s[right])
            return false;
        
        return rev(s, ++left);
    }
    
    int isPalindrome(string S) {
        if (rev(S, 0))
            return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends