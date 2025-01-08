class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0, n = words.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(words[j].size() >= words[i].size() and words[i] == words[j].substr(0, words[i].size()) and words[i] == words[j].substr(words[j].size() - words[i].size(), words[i].size())) {
                    ans++;
                }
            }
        }
        return ans;
    }
};