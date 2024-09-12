class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> uset;
        for(char c : allowed) {
            uset.emplace(c);
        }
        int ans = 0;
        for(auto& s : words) {
            bool check = true;
            for(char c : s) {
                if(uset.find(c) == uset.end()) {
                    check = false;
                    break;
                }
            }
            ans += check == true;
        }
        return ans;
    }
};