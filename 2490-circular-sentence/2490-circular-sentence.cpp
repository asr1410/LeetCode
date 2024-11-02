class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream s(sentence);
        string t;
        char sep = ' ';
        string p;
        while(getline(s, t, sep)) {
            if(p.size() == 0) {
                p = t;
            } else {
                if(p[p.size() - 1] != t[0]) {
                    return false;
                }
                p = t;
            }
        }
        return sentence[0] == p[p.size() - 1];
    }
};