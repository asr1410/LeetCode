class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> umap;
        istringstream iss1(s1), iss2(s2);
        string word;
        
        while (iss1 >> word) umap[word]++;
        while (iss2 >> word) umap[word]++;
        
        vector<string> ans;
        for(auto it : umap) {
            if(it.second == 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};