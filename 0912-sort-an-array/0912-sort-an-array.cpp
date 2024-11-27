class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int &a, int &b) {return a < b;});
        return nums;
    }
};