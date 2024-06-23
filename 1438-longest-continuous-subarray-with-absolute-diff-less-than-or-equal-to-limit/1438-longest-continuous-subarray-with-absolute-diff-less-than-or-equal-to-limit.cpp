class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> mn, mx;
        int i = 0, j = 0, n = nums.size();
        for(; j < n; j++) {
            while(mx.size() and nums[j] > mx.back()) mx.pop_back();
            while(mn.size() and nums[j] < mn.back()) mn.pop_back();
            mx.push_back(nums[j]);
            mn.push_back(nums[j]);
            if(mx.front() - mn.front() > limit) {
                if(mx.front() == nums[i]) mx.pop_front();
                if(mn.front() == nums[i]) mn.pop_front();
                ++i;
            }
        }
        return j - i;
    }
};