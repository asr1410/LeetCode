class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int& a, int& b) {
            string sa = to_string(a), sb = to_string(b);
            int i = 0, j = 0;
            while (i < sa.length() || j < sb.length()) {
                if (i == sa.length()) i = 0;
                if (j == sb.length()) j = 0;
                if (sa[i] != sb[j]) return sa[i] > sb[j];
                i++; j++;
                if (i == sa.length() && j == sb.length()) break;
            }
            return sa.length() > sb.length();
        });

        string ans;
        for(auto n : nums) {
            ans += to_string(n);
        }
        
        return ans[0] == '0' ? "0" : ans;
    }
};