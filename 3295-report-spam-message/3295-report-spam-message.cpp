class Solution {
public:
    bool reportSpam(vector<string>& m, vector<string>& bw) {
        unordered_set<string> uset(bw.begin(), bw.end());
        int count = 0;
        for(auto s : m) {
            if(uset.find(s) != uset.end()) {
                count++;
                if(count == 2) {
                    return true;
                }
            }
        }
        return false;
    }
};