class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), left = 0, right = 0, ans = 1;
        multiset<int> s;
        while(right < n) {
            s.insert(nums[right]);
            int diff = *s.rbegin() - *s.begin();
            while(diff > limit) {
                auto it = s.find(nums[left]);
                s.erase(it);
                left++;
                diff = *s.rbegin() - *s.begin();
            }
            ans = max(ans, (int)s.size());
            right++;
        }
        return ans;
    }
};