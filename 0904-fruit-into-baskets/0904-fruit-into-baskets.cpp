class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ff = 0, sf = 0, ffc = 0, sfc = 0, ans = 0, n = fruits.size();
        for(int i = 0, j = 0; i < n; i++) {
            if(ffc != 0 and sfc != 0 and ff != fruits[i] and sf != fruits[i]) {
                while(ffc != 0 and sfc != 0) {
                    ffc -= ff == fruits[j];
                    sfc -= sf == fruits[j];
                    j++;
                }
            }
            if(ffc == 0 or ff == fruits[i]) {
                if(ffc == 0) {
                    ff = fruits[i];
                }
                ffc++;
            } else {
                if(sfc == 0) {
                    sf = fruits[i];
                }
                sfc++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};