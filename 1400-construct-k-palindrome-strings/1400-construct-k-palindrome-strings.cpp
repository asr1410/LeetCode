class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) {
            return false;
        }
        vector<int> count(26, 0);
        for(char c : s) {
            count[c - 'a']++;
        }
        int oc = 0;
        for(int c : count) {
            oc += c & 1;
        }
        return oc <= k;
    }
};