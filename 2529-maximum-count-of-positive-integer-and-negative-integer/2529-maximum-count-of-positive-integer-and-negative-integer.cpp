class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pc = 0, nc = 0;
        for(const int& num : nums) {
            pc += num > 0;
            nc += num < 0;
        }
        return max(pc, nc);
    }
};