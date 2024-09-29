class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        long long l = 0, r = 0, a = 0, e = 0, i = 0, o = 0, u = 0, n = word.size(), ans = 0, count = 0;
        set<int> s;
        s.insert(n);  // Insert end of string as a sentinel
        for(int i = 0; i < n; i++) {
            if(word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u') {
                s.insert(i);
            }
        }
        while (r < n) {
            if(word[r] == 'a') a++;
            else if(word[r] == 'e') e++;
            else if(word[r] == 'i') i++;
            else if(word[r] == 'o') o++;
            else if(word[r] == 'u') u++;
            
            long long vowelCount = a + e + i + o + u;
            long long nonVowelCount = r - l + 1 - vowelCount;
            
            if(a && e && i && o && u && nonVowelCount >= k) {
                auto next_consonant = s.upper_bound(r);
                count = *next_consonant - r;
            }
            
            while (a && e && i && o && u && nonVowelCount >= k) {
                if(nonVowelCount == k) {
                    ans += count;
                }
                if(word[l] == 'a') a--;
                else if(word[l] == 'e') e--;
                else if(word[l] == 'i') i--;
                else if(word[l] == 'o') o--;
                else if(word[l] == 'u') u--;
                l++;
                nonVowelCount = r - l + 1 - (a + e + i + o + u);
            }
            r++;
        }
        return ans;
    }
};