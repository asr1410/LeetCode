class Solution {
public:
    long long gcd(long long int a, long long int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    long long lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }
    int maxLength(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            unsigned long long int a = nums[i], b = nums[i], c = nums[i];
            for(int j = i + 1; j < n; j++) {
                a = gcd(a, nums[j]);
                b = lcm(b, nums[j]);
                c = c * nums[j];
                if(a * b == c) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};