class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] < s[i - 1]) {
                if ((s[i] & 1) == (s[i - 1] & 1)) {
                    swap(s[i], s[i - 1]);
                    return s;
                }
            }
        }
        return s;
    }
};