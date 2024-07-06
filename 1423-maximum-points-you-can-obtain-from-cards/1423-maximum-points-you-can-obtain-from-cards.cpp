class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int ans = 0, psum = 0, right = cp.size() - 1;
        for(int i = 0; i < k; i++) {
            psum += cp[right];
            right--;
        }
        ans = psum;
        right++;
        for(int i = 0; i < k; i++) {
            psum = psum - cp[right] + cp[i];
            ans = max(ans, psum);
            right++;
        }
        return ans;
    }
};