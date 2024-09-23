class Solution {
public:
    
    long long validSubstringCount(string w1, string w2) {
        vector<int> c1(26), c2(26);
        for(char c : w2)
            c2[c - 'a']++;
        int l = 0, r = 0, n = w1.size();
        long long ans = 0;
        while(r < n) {
            bool flag = true;
            c1[w1[r] - 'a']++;
            for(int i = 0; i < 26; i++) {
                if(c1[i] < c2[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                while(l <= r) {
                    c1[w1[l] - 'a']--;
                    if(c1[w1[l] - 'a'] < c2[w1[l] - 'a']) {
                        c1[w1[l] - 'a']++;
                        break;
                    }
                    l++;
                }
                ans += (l + 1);
            }
            r++;
        }
        return ans;
    }
};