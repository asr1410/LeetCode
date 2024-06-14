class Solution {
public:
     int minIncrementForUnique(vector<int>& A) {
        map<int,int> count;
        for (int a : A) count[a]++;
        int res = 0, need = 0;
        for (auto x: count) {
            res += x.second * max(need - x.first, 0) + x.second * (x.second - 1) / 2;
            need = max(need, x.first) + x.second;
        }
        return res;
    }
};