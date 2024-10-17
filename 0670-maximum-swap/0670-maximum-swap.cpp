class Solution {
public:
    int maximumSwap(int num) {
        string ns = to_string(num);
        string sns = ns;
        sort(sns.begin(), sns.end(), greater<int>());
        int i = 0, n = ns.size();
        while(i < n and ns[i] == sns[i]) {
            i++;
        }
        if(i != n) {
            int r = n - 1;
            char f = sns[i];
            while(r >= 0 and ns[r] != f) {
                r--;
            }
            swap(ns[i], ns[r]);
            return stoi(ns);
        }
        return num;
    }
};