class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] < s[i - 1]) {
                if ((s[i] % 2) == (s[i - 1] % 2)) {
                    swap(s[i], s[i - 1]);
                    return s;
                }
            }
        }
        return s;
    }
};