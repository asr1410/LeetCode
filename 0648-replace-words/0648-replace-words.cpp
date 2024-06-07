class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string, string> umap;
        for(int i = 0; i < dictionary.size(); i++) {
            umap[dictionary[i]] = dictionary[i];
        }
        string ans = "";
        string s;
        stringstream ss(sentence);
        vector<string> v;
        while (getline(ss, s, ' ')) {
            v.push_back(s);
        }
        for(int i = 0; i < v.size(); i++) {
            string tmp = "";
            bool found = false;
            for(int j = 0; j < v[i].size(); j++) {
                tmp += v[i][j];
                if(umap.find(tmp) != umap.end()) {
                    ans += tmp;
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans += v[i];
            }
            ans += " ";
        }
        if (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};