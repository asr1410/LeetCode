class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(baskets[j] >= fruits[i]) {
                    baskets[j] = 0;
                    fruits[i] = 0;
                    break;
                }
            }
            ans += fruits[i] != 0;
        }
        return ans;
    }
};