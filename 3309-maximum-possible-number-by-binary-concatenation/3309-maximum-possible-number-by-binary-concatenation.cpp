class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        vector<string> snums;
        for(int num : nums) {
            string s;
            while(num) {
                s.push_back('0' + (num & 1));
                num >>= 1;
            }
            reverse(s.begin(), s.end());
            snums.push_back(s);
        }
        sort(snums.begin(), snums.end(), [](string& a, string& b) {
            return a + b > b + a;
        });
        int ans = 0;
        for(string s : snums) {
            for(char c : s) {
                ans |= (c - '0');
                ans <<= 1;
            }
        }
        return ans >> 1;
    }
};
