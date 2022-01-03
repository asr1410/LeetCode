class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int curr = 0, maxi = INT_MIN;
        for(auto && num : arr)
        {
            curr = max(curr + num, num);
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};