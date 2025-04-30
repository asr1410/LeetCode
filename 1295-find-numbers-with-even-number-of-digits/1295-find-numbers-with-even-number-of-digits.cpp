class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(const int& num : nums) {
            ans += (to_string(num).size() & 1) == 0;
        }
        return ans;
    }
};