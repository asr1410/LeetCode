class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int n = nums.size();
        for(int i = 0; i <= n - k; i++) {
            unordered_set<int> uset;
            for(int j = i; j < i + k; j++) {
                if(uset.find(nums[j]) == uset.end()) {
                    uset.insert(nums[j]);
                    ump[nums[j]]++;
                }
            }
        }

        int ans = -1;
        for(const auto& it : ump) {
            ans = max(ans, (it.second == 1) ? it.first : -1);
        }
        return ans;
    }
};