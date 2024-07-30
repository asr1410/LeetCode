class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> bcount(s.size() + 1);
        vector<int> acount(s.size() + 1);
        for(int i = 1, count = 0; i < bcount.size(); i++) {
            count += s[i - 1] == 'b';
            bcount[i] = count;
        }
        for(int i = acount.size() - 2, count = 0; i >= 0; i--) {
            count += s[i + 1] == 'a';
            acount[i] = count;
        }
        int ans = INT_MAX;
        for(int i = 0; i < acount.size(); i++) {
            ans = min(acount[i] + bcount[i], ans);
        }
        return ans;
    }
};