class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> count(k);
        for(int a : arr) {
            count[(a % k + k) % k]++;
        }
        if(count[0] % 2 == 1) {
            return false;
        }
        int l = 1, r = k - 1;
        while(l < r) {
            if(count[l] != count[r]) {
                return false;
            }
            l++;
            r--;
        }
        if(arr.size() % 2 == 1 && count[l] % 2 == 1) {
            return false;
        }
        return true;
    }
};
