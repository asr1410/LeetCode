class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xr = 0;
        for(auto&& num: nums) {
            xr ^= num;
        }
        
        long long bit = xr & ~(xr - 1);
        
        long long first = 0, second = 0;
        for(auto&& num: nums) {
            if((num & bit) != 0) {
                first ^= num;
            } else {
                second ^= num;
            }
        }
        return {(int)first, (int)second};
    }
};