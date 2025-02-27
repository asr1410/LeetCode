class Solution {
public:
    unordered_map<int, int> indexMap;  // Stores indices of elements in arr
    unordered_map<long long, int> dp;  // Memo table (Key: prev * 1000 + curr)
    
    int helper(int prev, int curr, vector<int>& arr) {
        if (prev >= 0 && curr >= 0) {
            long long key = prev * 1000LL + curr; // Unique key for memoization
            if (dp.count(key)) return dp[key];  // Return memoized result
        }

        int ans = 0;
        int target = arr[prev] + arr[curr];  
        if (indexMap.count(target)) {
            int next = indexMap[target];
            ans = 1 + helper(curr, next, arr);  // Continue sequence
        }
        
        if (prev >= 0 && curr >= 0) dp[prev * 1000LL + curr] = ans;  // Store result
        return ans;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0; // No valid sequence

        // Map each value to its index for O(1) lookups
        for (int i = 0; i < n; i++) indexMap[arr[i]] = i;
        
        int maxLen = 0;
        // Try all pairs as the starting two elements of the sequence
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int length = 2 + helper(i, j, arr); // At least 2 elements
                maxLen = max(maxLen, length);
            }
        }
        return maxLen >= 3 ? maxLen : 0;
    }
};
