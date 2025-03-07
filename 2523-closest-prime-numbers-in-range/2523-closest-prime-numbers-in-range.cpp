class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> mark(right + 1, 0);
        mark[1] = 1;
        for(int i = 2; i <= right; i++) {
            if(mark[i] == 0) {
                mark[i] = 1;
                for(int j = i + i; j <= right; j += i) {
                    mark[j] = 2;
                }
            }
        }
        int count = 0;
        for(int i = left; i <= right; i++) {
            count += mark[i] == 1;
        }
        // for(int i = 0; i <= right; i++) {
        //     cout << mark[i] << " ";
        // }
        if(count < 2) {
            return {-1, -1};
        }
        int a = -1, b = -1, diff = INT_MAX;
        vector<int> ans{-1, -1};
        for(int i = max(left, 2); i <= right; i++) {
            if(mark[i] == 1) {
                if(a == -1) {
                    a = i;
                } else if(b == -1) {
                    b = i;
                    ans[0] = a, ans[1] = b;
                    diff = b - a;
                } else {
                    a = b;
                    b = i;
                    if(b - a < diff) {
                        ans[0] = a, ans[1] = b;
                        diff = b - a;
                    }
                }
            }
        }
        return ans;
    }
};