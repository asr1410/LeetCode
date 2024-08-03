class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(arr.size() != target.size()) {
            return false;
        }
        vector<int> map(1001);
        for(int i = 0; i < arr.size(); i++) {
            map[target[i]]++;
            map[arr[i]]--;
        }
        for(int i = 0; i < 1001; i++) {
            if(map[i]) {
                return false;
            }
        }
        return true;
    }
};