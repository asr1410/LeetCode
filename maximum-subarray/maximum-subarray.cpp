class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int curr = 0, maxi = INT_MIN;
    for (auto &&i : arr)
    {
        curr = max(i, curr + i);
        maxi = max(curr, maxi);
    }
    return maxi;
    }
};