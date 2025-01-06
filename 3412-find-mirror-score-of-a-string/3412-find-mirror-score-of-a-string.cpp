class Solution {
public:
    long long calculateScore(string s) {
        unordered_map<char, vector<int>> ump;
        long long n = s.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            char c = 'a' + 25 - s[i] + 'a';
            if(ump[c].size() != 0) {
                ans += i - ump[c].back();
                ump[c].pop_back();
            } else {
                ump[s[i]].push_back(i);
            }
        }
        return ans;
    }
};