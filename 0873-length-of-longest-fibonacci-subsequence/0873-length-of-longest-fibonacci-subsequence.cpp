class Solution {
public:
    unordered_map<int, int> indexMap;
    int dp[1001][1001];

    int helper(int prev, int curr, vector<int>& arr) {
        if (dp[prev][curr] != -1)
            return dp[prev][curr];

        int ans = 0;
        int target = arr[prev] + arr[curr];
        
        if (indexMap.count(target)) {
            int next = indexMap[target];
            ans = 1 + helper(curr, next, arr);
        }
        return dp[prev][curr] = ans;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) indexMap[arr[i]] = i;
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int length = 2 + helper(i, j, arr);
                maxLen = max(maxLen, length);
            }
        }
        return maxLen >= 3 ? maxLen : 0;
    }
};
