class Solution {
public:
    unordered_map<int, int> indexMap;
    unordered_map<long long, int> dp;
    
    int helper(int prev, int curr, vector<int>& arr) {
        long long key = prev * 1000LL + curr;
        if (dp.count(key)) return dp[key];

        int ans = 0;
        int target = arr[prev] + arr[curr];  
        if (indexMap.count(target)) {
            int next = indexMap[target];
            ans = 1 + helper(curr, next, arr);
        }
        
        if (prev >= 0 && curr >= 0) dp[prev * 1000LL + curr] = ans;
        return ans;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;
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
