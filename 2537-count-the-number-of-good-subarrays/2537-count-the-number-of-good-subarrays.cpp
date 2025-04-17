class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int l = 0, n = nums.size();
        long long ans = 0, totalPairs = 0;

        for (int r = 0; r < n; ++r) {
            totalPairs += freq[nums[r]];
            freq[nums[r]]++;
            while (totalPairs >= k) {
                ans += n - r;
                totalPairs = totalPairs - freq[nums[l]] + 1;
                freq[nums[l]]--;
                l++;
            }
        }

        return ans;
    }
};
