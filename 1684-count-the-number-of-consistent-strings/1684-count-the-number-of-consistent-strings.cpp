class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> mark(26);
        for(char c : allowed) {
            mark[c - 'a'] = 1;
        }
        int ans = 0;
        for(auto& s : words) {
            bool check = true;
            for(char c : s) {
                if(mark[c - 'a'] == 0) {
                    check = false;
                    break;
                }
            }
            ans += check == true;
        }
        return ans;
    }
};