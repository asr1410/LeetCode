class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uset;
        int ans = 0, n = s.size();
        for(int i = 0, j = 0; j < n; j++) {
            while(uset.find(s[j]) != uset.end()) {
                uset.erase(s[i]);
                i++;
            }
            uset.insert(s[j]);
            ans = max(ans, (int)uset.size());
        }
        return ans;
    }
};