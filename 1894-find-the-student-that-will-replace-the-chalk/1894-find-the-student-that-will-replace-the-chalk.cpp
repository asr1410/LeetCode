class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= total;
        int i = 0;
        while(k >= chalk[i]) {
            k -= chalk[i];
            i++;
        }
        return i;
    }
};