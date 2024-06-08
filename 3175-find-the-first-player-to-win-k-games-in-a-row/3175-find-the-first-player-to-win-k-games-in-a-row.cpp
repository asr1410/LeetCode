class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int a = skills[0], n = skills.size(), res = 0, curr = 0;
        for(int i = 1; i < n; i++) {
            if(skills[i] > a) {
                a = skills[i];
                curr = 0;
                res = i;
            }
            if (++curr == k) return res;
        }
        return res;
    }
};