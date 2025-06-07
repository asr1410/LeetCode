class Solution {
public:
    string clearStars(string s) {
        map<char, set<int>> cnt;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                cnt[s[i]].insert(i);
            } else {
                auto it = cnt.begin();
                auto lastIdxIt = prev(it->second.end());
                s[*lastIdxIt] = '0';
                it->second.erase(lastIdxIt);
                if (it->second.empty()) {
                    cnt.erase(it);
                }
            }
        }

        string res;
        for (char c : s) {
            if (c != '*' && c != '0') res += c;
        }
        return res;
    }
};
