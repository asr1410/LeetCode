class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int l = 0, r = 0, n = word.size(), ans = 0;
        array<int, 5> vowels = {0, 0, 0, 0, 0};
        
        auto isVowel = [](char c) -> int {
            switch(c) {
                case 'a': return 0;
                case 'e': return 1;
                case 'i': return 2;
                case 'o': return 3;
                case 'u': return 4;
                default: return -1;
            }
        };

        while (r < n) {
            int v = isVowel(word[r]);
            if (v != -1) vowels[v]++;

            while (vowels[0] && vowels[1] && vowels[2] && vowels[3] && vowels[4] && 
                   r - l + 1 - (vowels[0] + vowels[1] + vowels[2] + vowels[3] + vowels[4]) >= k) {
                if (r - l + 1 - (vowels[0] + vowels[1] + vowels[2] + vowels[3] + vowels[4]) == k) {
                    int t = r + 1, count = 1;
                    while (t < n && isVowel(word[t]) != -1) {
                        count++;
                        t++;
                    }
                    ans += count;
                }
                
                int vl = isVowel(word[l]);
                if (vl != -1) vowels[vl]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};