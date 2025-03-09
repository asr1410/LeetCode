class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), ans = 0;
        if(colors[0] == colors[n - 1]) {
            for(int i = 1, count = 1; i < n; i++) {
                if(colors[i - 1] != colors[i]) {
                    count++;
                    ans += count >= k;
                } else {
                    count = 1;
                }
            }
            return ans;
        }
        for(int i = 1, j = 1, count = 1; i < n + n; i++, j++) {
            if(colors[(i - 1) % n] != colors[i % n]) {
                if(i >= n and i % n == k - 1) {
                    break;
                }
                count++;
                ans += count >= k;
            } else {
                if(j >= n) {
                    break;
                }
                count = 1;
            }
        }
        return ans;
    }
};