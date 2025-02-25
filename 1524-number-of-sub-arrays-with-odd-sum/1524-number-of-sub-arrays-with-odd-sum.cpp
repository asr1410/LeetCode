class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int ans = 0, tsum = 0;
        int oc = 0, ec = 1;

        for (const int num : arr) {
            tsum += num;
            if (tsum & 1) {
                ans += ec;
                oc++;
            } else {
                ans += oc;
                ec++;
            }

            ans %= MOD;
        }

        return ans;
    }
};