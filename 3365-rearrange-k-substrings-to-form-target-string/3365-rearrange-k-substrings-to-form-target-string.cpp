class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string, int> ump;
        int n = s.size(), z = n / k;
        for (int i = 0; i < n; i += z) {
            ump[s.substr(i, z)]++;
            ump[t.substr(i, z)]--;
        }
        for(auto it : ump) {
            if(it.second != 0) {
                return false;
            }
        }
        return true;
    }
};