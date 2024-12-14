class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> s;
        s.insert(nums[0]);
        long long ans = 1;
        int n = nums.size();
        for (int r = 1, l = 0; r < n; r++) {
            s.insert(nums[r]);
            while (*s.rbegin() - *s.begin() > 2) {
                s.erase(s.find(nums[l]));
                l++;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};
