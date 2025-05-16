class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int prev = groups[0];
        ans.push_back(words[0]);
        for(int i = 1; i < groups.size(); i++) {
            if(groups[i] != prev) {
                prev ^= 1;
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};