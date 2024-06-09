#define ll long long
int dp[2001][4000];
int find(int pos, int sum, const vector<int> &nums) {
    if (pos == nums.size()) return 0;
    if (dp[pos][sum] != -1) return dp[pos][sum];
    int ans = find(pos + 1, sum, nums);
    if (nums[pos] > sum) {
        ans = max(ans, nums[pos] + find(pos + 1, sum + nums[pos], nums));
    }
    return dp[pos][sum] = ans;
}

class Solution {
public:
    int maxTotalReward(vector<int>& rv) {
        memset(dp, -1, sizeof(dp));
        sort(rv.begin(), rv.end());
        return find(0, 0, rv);
    }
};