class Solution {
public:
    int strStr(string_view haystack, string_view needle) {
        if (haystack.length() < needle.length()) return -1;
        for(size_t i = 0; i <= haystack.length() - needle.length(); i++) {
            if(haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};