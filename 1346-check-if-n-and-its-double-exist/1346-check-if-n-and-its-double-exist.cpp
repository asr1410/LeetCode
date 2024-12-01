class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> ump;
        for(auto a : arr) {
            if((a % 2 == 0 and ump.find(a / 2) != ump.end()) or ump.find(a * 2) != ump.end()) {
                return true;
            }
            ump[a]++;
        }
        return false;
    }
};