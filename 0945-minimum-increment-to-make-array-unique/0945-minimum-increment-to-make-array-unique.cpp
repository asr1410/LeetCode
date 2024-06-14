class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> map(100001);
        for(auto num:nums) {
            map[num]++;
        }
        int ans = 0;
        for(int i = 0; i < 100000; i++) {
            if(map[i] > 1) {
                int temp = map[i] - 1;
                ans += temp;
                map[i + 1] += temp;
            }
        }
        ans += (map[100000] * (map[100000] - 1)) / 2;
        return ans;
    }
};