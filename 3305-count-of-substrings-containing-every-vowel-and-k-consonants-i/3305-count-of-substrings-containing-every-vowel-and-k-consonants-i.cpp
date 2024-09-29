class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int l = 0, r = 0, vowels[5] = {0};
        int n = word.size(), ans = 0;

        while (r < n) {
            if (word[r] == 'a') vowels[0]++;
            else if (word[r] == 'e') vowels[1]++;
            else if (word[r] == 'i') vowels[2]++;
            else if (word[r] == 'o') vowels[3]++;
            else if (word[r] == 'u') vowels[4]++;
            
            while (vowels[0] && vowels[1] && vowels[2] && vowels[3] && vowels[4] && 
                   r - l + 1 - (vowels[0] + vowels[1] + vowels[2] + vowels[3] + vowels[4]) >= k) {
                int t = r + 1, count = 1;
                while (t < n && (word[t] == 'a' || word[t] == 'e' || word[t] == 'i' || word[t] == 'o' || word[t] == 'u')) {
                    count++;
                    t++;
                }
                
                if (r - l + 1 - (vowels[0] + vowels[1] + vowels[2] + vowels[3] + vowels[4]) == k) {
                    ans += count;
                }
                
                if (word[l] == 'a') vowels[0]--;
                else if (word[l] == 'e') vowels[1]--;
                else if (word[l] == 'i') vowels[2]--;
                else if (word[l] == 'o') vowels[3]--;
                else if (word[l] == 'u') vowels[4]--;
                
                l++;
            }
            r++;
        }
        return ans;
    }
};
