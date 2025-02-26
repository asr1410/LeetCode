class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans1 = 0, ans2 = 0, temp = 0;
        for(const int num : nums) {
            temp = max(temp + num, num);
            ans1 = max(ans1, temp);
        }
        temp = 0;
        for(const int num : nums) {
            temp = min(temp + num, num);
            ans2 = min(ans2, temp);
        }
        return max(abs(ans1), abs(ans2));
    }
};