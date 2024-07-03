class Solution {
public:
    int countPrimes(int n) {
        vector<bool> count(n);
        for(int i = 2; i < n; i++) {
            if(count[i] == 0) {
                for(int j = i + i; j < n; j += i) {
                    count[j] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 2; i < n; i++) {
            ans += count[i] == 0;
        }
        return ans;
    }
};