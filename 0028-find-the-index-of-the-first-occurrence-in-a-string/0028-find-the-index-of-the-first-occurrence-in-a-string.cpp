class Solution {
public:
    int strStr(string_view haystack, string_view needle) {
        for(size_t i = 0; i < haystack.length(); i++) {
            if(haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};