class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1) {
            return 0;
        }
        vector<int> map(n);
        for(int i = 2; i < n; i++) {
            if(map[i] != 1) {
                for(int j = i + i; j < n; j += i) {
                    map[j] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 2; i < n; i++) {
            ans += map[i] == 0;
        }
        return ans;
    }
};