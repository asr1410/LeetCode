class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> map(200003);
        for(auto num:nums) {
            map[num]++;
        }
        int ans = 0;
        for(int i = 0; i < 200002; i++) {
            if(map[i] > 1) {
                int temp = map[i] - 1;
                ans += temp;
                map[i + 1] += temp;
            }
        }
        return ans;
    }
};