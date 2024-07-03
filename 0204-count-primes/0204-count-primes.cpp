class Solution {
public:
    int countPrimes(int n) {
        vector<char> count(n, 0);
        int ans = 0;
        for(int i = 2; i < n; i++) {
            if(count[i] == 0) {
                ans++;
                for(int j = i + i; j < n; j += i) {
                    count[j] = 1;
                }
            }
        }
        return ans;
    }
};