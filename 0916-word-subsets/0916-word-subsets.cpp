class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mark(26, 0);
        for(auto&& word2 : words2) {
            vector<int> temp(26, 0);
            for(auto w2 : word2) {
                temp[w2 - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                mark[i] = max(mark[i], temp[i]);
            }
        }
        vector<string> ans;
        for(auto&& word1 : words1) {
            vector<int> temp(26, 0);
            for(auto w1 : word1) {
                temp[w1 - 'a']++;
            }
            bool check = true;
            for(int i = 0; i < 26; i++) {
                if(temp[i] < mark[i]) {
                    check = false;
                    break;
                }
            }
            if(check) {
                ans.push_back(word1);
            }
        }
        return ans;
    }
};