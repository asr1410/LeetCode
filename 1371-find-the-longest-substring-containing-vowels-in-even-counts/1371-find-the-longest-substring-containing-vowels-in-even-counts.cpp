#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> first_occurrence;
        first_occurrence[0] = -1;
        int bitmask = 0;
        int max_length = 0;

        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == 'a') {
                bitmask ^= 1 << 0;
            } else if (s[j] == 'e') {
                bitmask ^= 1 << 1;
            } else if (s[j] == 'i') {
                bitmask ^= 1 << 2;
            } else if (s[j] == 'o') {
                bitmask ^= 1 << 3;
            } else if (s[j] == 'u') {
                bitmask ^= 1 << 4;
            }

            if (first_occurrence.find(bitmask) != first_occurrence.end()) {
                max_length = max(max_length, j - first_occurrence[bitmask]);
            } else {
                first_occurrence[bitmask] = j;
            }
        }

        return max_length;
    }
};