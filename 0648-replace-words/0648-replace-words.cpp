class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string, string> umap;
        for(int i = 0; i < dictionary.size(); i++) {
            umap[dictionary[i]] = dictionary[i];
        }
        string ans = "";
        string s;
        stringstream ss(sentence);  // Corrected from 'str' to 'sentence'
        vector<string> v;
        while (getline(ss, s, ' ')) {
            v.push_back(s);
        }
        for(int i = 0; i < v.size(); i++) {
            string tmp = "";
            bool found = false;  // To check if we found a root
            for(int j = 0; j < v[i].size(); j++) {  // Corrected from 'v[0]' to 'v[i]'
                tmp += v[i][j];
                if(umap.find(tmp) != umap.end()) {
                    ans += tmp;
                    found = true;  // Set found to true if a root is found
                    break;
                }
            }
            if (!found) {  // If no root is found, add the original word
                ans += v[i];
            }
            ans += " ";
        }
        if (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();  // Remove the trailing space
        }
        return ans;
    }
};