class Solution {
public:
    int recursion(int cur_ind,  string& str, int& len, vector<int>& dp){
        
        // if we reach at index where value of char is zero
        if(cur_ind<=len-1 and str[cur_ind]=='0'){
            return dp[cur_ind]=0;
        }
        
        // if we reach last index or reach to string length
        if(cur_ind==len-1 or cur_ind==len){
            return 1;
        }
        
        // if we already have an entry on dp table
        if(dp[cur_ind]!=0){
            return dp[cur_ind];
        }
        
        // stort the one and two char in integer form 
        int char1=str[cur_ind]-'0', char2=10*(str[cur_ind]-'0')+(str[cur_ind+1]-'0');
        
        // we can always take 1 char except when it is zero and for zero we already return from above code
        dp[cur_ind]=recursion(cur_ind+1, str, len, dp);
        
        // we can take two char if form interger value less than or equal to 26
        if(char2<=26){
             // as answer always fits in a 32-bit integer so we dont have to take long long 
            dp[cur_ind]+=recursion(cur_ind+2, str, len, dp);
        }
        
        return dp[cur_ind];
    }
    
    int numDecodings(string s) {
        
        // length of string
        int n=s.size();
        
        // declaring 1D dp table 
        vector<int>dp(n,0);
        
        return recursion(0,s,n,dp);
    }
};