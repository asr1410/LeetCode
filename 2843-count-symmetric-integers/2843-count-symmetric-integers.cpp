class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; i++) {
            string s = to_string(i);
            ans += !(s.size() & 1) and s.size() == 2 and s[0] == s[1];
            ans += !(s.size() & 1) and s.size() == 4 and s[0] + s[1] == s[2] + s[3];
        }
        return ans;
    }
};