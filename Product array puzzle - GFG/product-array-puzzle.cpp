// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution
{
     bool anyElement(vector<int> &mark, int n, vector<long long int> &nums)
     {
          for (auto &&num : mark)
          {
               if (num != n && nums[num] == 0)
               {
                    return false;
               }
          }
          return true;
     }

public:
     // nums: given vector
     // return the Product vector P that hold product except self at each index
     vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
     {
          vector<long long int> ans;
          vector<int> mark;
          long long int total = 1;
          for (int i = 0; i < n; i++)
          {
               if (nums[i])
               {
                    total *= nums[i];
               }
               else
               {
                    mark.push_back(i);
               }
          }
          for (int i = 0; i < n; i++)
          {
               if (anyElement(mark, i, nums))
               {
                    if (nums[i] == 0)
                    {
                         ans.push_back(total);
                    }
                    else
                    {
                         ans.push_back(total / nums[i]);
                    }
               }
               else
               {
                    ans.push_back(0);
               }
          }
          return ans;
     }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends