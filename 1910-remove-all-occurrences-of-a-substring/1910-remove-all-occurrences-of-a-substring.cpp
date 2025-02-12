class Solution {
public:
    string removeOccurrences(string s, string p) {
        int t = p.size();
        for(int check = 1, i = 0; check != 0;) {
            check = 0, i = 0;
            string temp;
            while(i < s.size()) {
                if(s.substr(i, t) == p) {
                    i += t;
                    check = true;
                    break;
                } else {
                    temp.push_back(s[i]);
                    i++;
                }
            }
            temp += s.substr(i);
            s = temp;
        }
        return s;
    }
};