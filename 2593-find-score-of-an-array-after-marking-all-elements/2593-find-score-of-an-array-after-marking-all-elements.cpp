class Solution {
public:
    long long findScore(vector<int>& nums) {
        map<int, set<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].insert(i);
        }
        vector<int> vis(n, 0);
        long long ans = 0;
        for (auto& it : mp) {
            int val = it.first;
            for (auto idx : it.second) {
                if (vis[idx] == 0) {
                    ans += val;
                    vis[idx] = 1;
                    if (idx > 0 && vis[idx - 1] == 0) {
                        vis[idx - 1] = 1;
                        mp[nums[idx - 1]].erase(idx - 1);
                        if (mp[nums[idx - 1]].empty()) {
                            mp.erase(nums[idx - 1]);
                        }
                    }
                    if (idx < n - 1 && vis[idx + 1] == 0) {
                        vis[idx + 1] = 1;
                        mp[nums[idx + 1]].erase(idx + 1);
                        if (mp[nums[idx + 1]].empty()) {
                            mp.erase(nums[idx + 1]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
