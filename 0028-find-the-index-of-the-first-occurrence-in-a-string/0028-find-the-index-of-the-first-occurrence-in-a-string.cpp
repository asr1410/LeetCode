class Solution {
public:
    int strStr(string haystack, string needle) {
        string_view hs = haystack;
        int t = needle.size();
        for(int i = 0; i < hs.size(); i++) {
            if(hs.substr(i, t) == needle) {
                return i;
            }
        }
        return -1;
    }
};