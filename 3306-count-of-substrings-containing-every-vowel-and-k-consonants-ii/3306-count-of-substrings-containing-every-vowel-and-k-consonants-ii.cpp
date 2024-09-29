class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        long long l = 0, r = 0, a = 0, e = 0, i = 0, o = 0, u = 0, n = word.size(), ans = 0, count = 0;
        set<int> s;
        s.insert(n);
        for(int i = 0; i < n; i++) {
            if(word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u') {
                s.insert(i);
            }
        }
        while (r < n) {
            a += word[r] == 'a';
            e += word[r] == 'e';
            i += word[r] == 'i';
            o += word[r] == 'o';
            u += word[r] == 'u';
            long long vc = a + e + i + o + u;
            long long nvc = r - l + 1 - vc;
            if(a && e && i && o && u && nvc >= k) {
                count = *s.upper_bound(r) - r;
            }
            while (a && e && i && o && u && nvc >= k) {
                if(nvc == k) {
                    ans += count;
                }
                a -= word[l] == 'a';
                e -= word[l] == 'e';
                i -= word[l] == 'i';
                o -= word[l] == 'o';
                u -= word[l] == 'u';
                l++;
                nvc = r - l + 1 - (a + e + i + o + u);
            }
            r++;
        }
        return ans;
    }
};