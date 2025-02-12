class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> ump;
        int ans = -1;
        for(const int& num : nums) {
            string s = to_string(num);
            int temp = 0;
            for(const char& c : s) {
                temp += (c - '0');
            }
            if(ump.find(temp) != ump.end()) {
                ans = max(ans, ump[temp] + num);
            }
            ump[temp] = max(num, ump[temp]);
        }
        return ans;
    }
};