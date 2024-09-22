class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        for(int i = 0, cnt = 1; i < n; i++) {
            ans[i] = cnt;
            if(cnt * 10 <= n) {
                cnt *= 10;
            } else {
                if(cnt == n) {
                    cnt /= 10;
                }
                cnt++;
                while(cnt % 10 == 0) {
                    cnt /= 10;
                }
            }
        }
        return ans;
    }
};