class Solution {
public:
    int minDays(vector<int>& bd, int m, int k) {
        if(m > bd.size() / k) {
            return -1;
        }
        int l = 1, r = 1000000000, n = bd.size();
        while(l < r) {
            int mid = (l + r) / 2, count = 0, temp = 0;
            for(int i = 0; i < n; i++) {
                if(bd[i] <= mid) {
                    count++;
                    if(count == k) {
                        temp++;
                        count = 0;
                    }
                } else {
                    count = 0;
                }
            }
            if(temp < m) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};