class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 1, n = ratings.size(), last = 0, i = 1, candy = 1;
        while(i < n) {
            while(i < n and ratings[i - 1] < ratings[i]) {
                candy++;
                ans += candy;
                i++;
            }
            last = candy;
            candy = 1;
            while(i < n and ratings[i - 1] > ratings[i]) {
                ans += candy;
                candy++;
                i++;
            }
            ans += max(last, candy) - last;
            while(i < n and ratings[i - 1] == ratings[i]) {
                ans += 1;
                i++;
            }
            candy = 1;
        }
        return ans;
    }
};