class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int curr = 0, maxi = INT_MIN;
        for(int i = 0; i < arr.size(); i++)
        {
            if(curr + arr[i] < arr[i])
                curr = arr[i];
            else
                curr += arr[i];
            maxi = max(maxi,curr);
        }
        return maxi;
    }
};