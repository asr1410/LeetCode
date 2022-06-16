class Solution {
public:
    string longestPalindrome(string s) 
    {
        int lenMax = 0;
        string res;
        
        for(int i=0; i<s.length(); i++)
        {
            string odd = pali_subs(s, i, i); //start from same index for odd length palindrome
            long_subs(odd, res, lenMax);
            string even = pali_subs(s, i, i+1); //start from adjacent index for even length palindrome
            long_subs(even, res, lenMax);
        }
        return res;
    }
	
	string pali_subs(string &s, int L, int R)
    {
        int n=s.size();
        while(L>=0 && R<n) //iterate until L and R cross the boundary
        {
            if(s[L]!=s[R]) break;
            L--;
            R++;
        }
        return s.substr(L+1, R-1-L); //return palindromic substring
    }
    
    void long_subs(string &new_s, string &res, int &lenMax)
    {
        if(new_s.size()>lenMax) //if 
        {
            res = new_s;
            lenMax = new_s.size();
        }
    }
};