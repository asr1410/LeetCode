class Solution {
public:
    string removeOccurrences(string s, string p) {
        int check = true, t = p.size();
        while(check) {
            check = false;
            string temp;
            int i = 0;
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