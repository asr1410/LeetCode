class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0, n = pref.size();
        for(auto&& word : words) {
            ans += word.substr(0, n) == pref;
        }
        return ans;
    }
};