class Solution {
public:
    int minimumLength(string s) {
        vector<int> count(26, 0);
        for(auto c : s) {
            count[c - 'a']++;
        }
        int ans = 0;
        for(auto c : count) {
            if(c & 1) {
                ans++;
            }
            if(c != 0 and (c & 1) == 0) {
                ans += 2;
            }
        }
        return ans;
    }
};